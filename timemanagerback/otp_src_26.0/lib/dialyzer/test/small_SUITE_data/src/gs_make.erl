%% ``Licensed under the Apache License, Version 2.0 (the "License");
%% you may not use this file except in compliance with the License.
%% You may obtain a copy of the License at
%%
%%     http://www.apache.org/licenses/LICENSE-2.0
%%
%% Unless required by applicable law or agreed to in writing, software
%% distributed under the License is distributed on an "AS IS" BASIS,
%% WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
%% See the License for the specific language governing permissions and
%% limitations under the License.
%%
%% The Initial Developer of the Original Code is Ericsson Utvecklings AB.
%% Portions created by Ericsson are Copyright 1999, Ericsson Utvecklings
%% AB. All Rights Reserved.''
%%
%%     $Id: gs_make.erl,v 1.1 2008/12/17 09:53:50 mikpe Exp $
%%
-module(gs_make).

-export([start/0]).

start() ->
    Terms = the_config(),
    DB=fill_ets(Terms),
    {ok,OutFd} = file:open("gstk_generic.hrl", [write]),
    put(stdout,OutFd),
%    io:format("terms: ~p ~n ets:~p~n",[Terms,ets:tab2list(DB)]),
    p("% Don't edit this file. It was generated by gs_make:start/0 "),
    p("at ~p-~p-~p, ~p:~p:~p.\n\n",
      lists:append(tuple_to_list(date()),tuple_to_list(time()))),
    gen_out_opts(DB),
    gen_read(DB),
    file:close(OutFd),
    {ok,"gstk_generic.hrl",DB}.

fill_ets(Terms) ->
    DB = ets:new(gs_mapping,[bag,public]),
    fill_ets(DB,Terms).

fill_ets(DB,[]) -> DB;
fill_ets(DB,[{Objs,Opt,Fun,Access}|Terms]) ->
    fill_ets(DB,lists:flatten(Objs),Opt,Fun,Access),
    fill_ets(DB,Terms).

fill_ets(_DB,[],_,_,_) -> done;
fill_ets(DB,[Obj|Objs],Opt,Fun,rw) ->
    ets:insert(DB,{Obj,Opt,Fun,read}),
    ets:insert(DB,{Obj,Opt,Fun,write}),
    fill_ets(DB,Objs,Opt,Fun,rw);
fill_ets(DB,[Obj|Objs],Opt,Fun,r) ->
    ets:insert(DB,{Obj,Opt,Fun,read}),
    fill_ets(DB,Objs,Opt,Fun,r);
fill_ets(DB,[Obj|Objs],Opt,Fun,w) ->
    ets:insert(DB,{Obj,Opt,Fun,write}),
    fill_ets(DB,Objs,Opt,Fun,w).



gen_out_opts(DB) ->
    ObjTypes = lists:flatten(ordsets:from_list(ets:match(DB,{'$1','_','_',write}))),
    p("out_opts([Option|Options],Gstkid,TkW,DB,ExtraArg,S,P,C) ->\n"),
    p("  {Opt,Val} =\n"),
    p("    case Option of \n"),
    p("      {{default,Cat,Key},V} -> {default,{Cat,{Key,V}}};\n"),
    p("      {_Key,_V} -> Option;\n"),
    p("      {default,Cat,Opti} -> {default,{Cat,Opti}};\n"),
    p("      Atom when atom(Atom) -> {Atom,undefined};\n"),
    p("      _ -> {error, {invalid_option,Option}}\n"),
    p("    end,\n"),
    p("  case Gstkid#gstkid.objtype of\n"),
    gen_out_type_case_clauses(merge_types(ObjTypes),DB),
    p("    Q -> exit({internal_error,unknown_objtype,Q})\n"),
    p("  end;\n"),
    p("out_opts([],_Gstkid,_TkW,_DB,_ExtraArg,S,P,C) -> \n"),
    p("  {S,P,C}.\n").


gen_out_type_case_clauses([],_DB) -> done;
gen_out_type_case_clauses([Objtype|Objtypes],DB) ->
    OptsFuns = lists:map(fun (L) -> list_to_tuple(L) end,
			 ets:match(DB,{Objtype,'$1','$2',write})),
    p("   ~p -> \ncase Opt of\n",[Objtype]),
    gen_opt_case_clauses(merge_opts(opt_prio(),OptsFuns)),
    p("  _ -> \n"),
    p("    handle_external_opt_call([Option|Options],Gstkid,TkW,DB,ExtraArg,"
      "                             gstk_~p:option(Option,Gstkid,TkW,DB,ExtraArg),S,P,C)\n",
      [Objtype]),
    p("  end;\n"),
    gen_out_type_case_clauses(Objtypes,DB).

gen_opt_case_clauses([]) ->
    done;
gen_opt_case_clauses([{Opt,Fun}|OptFuncs]) ->
    p("  ~p ->\n",[Opt]),
    p("    ~p(Val,Options,Gstkid,TkW,DB,ExtraArg,S,P,C);\n",[Fun]),
    gen_opt_case_clauses(OptFuncs).

gen_read(DB) ->
    ObjTypes = lists:flatten(ordsets:from_list(ets:match(DB,{'$1','_','_',read}))),
    p("read_option(DB,Gstkid,TkW,Option,ExtraArg) ->\n"),
    p("  Key = case Option of\n"),
    p("    Atom when atom(Atom) -> Atom;\n"),
    p("    Opt when tuple(Opt) -> element(1,Opt)\n"),
    p("  end,\n"),
    p("  case Gstkid#gstkid.objtype of\n"),
    gen_read_type_clauses(merge_types(ObjTypes),DB),
    p("    Q -> exit({internal_error,unknown_objtype,Q})\n"),
    p("  end.\n").


gen_read_type_clauses([],_) -> done;
gen_read_type_clauses([Objtype|Objtypes],DB) ->
    OptsFuns = lists:map(fun (L) -> list_to_tuple(L) end,
			 ets:match(DB,{Objtype,'$1','$2',read})),
    p("  ~p -> \ncase Key of\n",[Objtype]),
    gen_readopt_case_clauses(merge_opts(opt_prio(),OptsFuns)),
    p("  _ -> \nhandle_external_read(gstk_~p:read_option(Option,Gstkid,TkW,DB,ExtraArg))\n",[Objtype]),
    p("  end;\n"),
    gen_read_type_clauses(Objtypes,DB).

gen_readopt_case_clauses([]) ->
    done;
gen_readopt_case_clauses([{Opt,Fun}|OptFuncs]) ->
    p("  ~p -> \n~p(Option,Gstkid,TkW,DB,ExtraArg);\n",[Opt,Fun]),
    gen_readopt_case_clauses(OptFuncs).


p(Str) ->
    ok = io:format(get(stdout),Str,[]).

p(Format,Data) ->
    ok = io:format(get(stdout),Format,Data).

%%----------------------------------------------------------------------
%% There items should be placed early in a case statement.
%%----------------------------------------------------------------------
obj_prio() -> [rectangle,line,gridline,image,button,canvas,checkbutton,radiobutton].
opt_prio() -> [x,y,width,height,move,coords,data].

merge_types(Types) ->
    T2 = ordsets:from_list(Types),
    P2 = ordsets:from_list(obj_prio()),
    obj_prio() ++ ordsets:subtract(T2, P2).

merge_opts([],L) -> L;
merge_opts([Opt|Opts],Dict) ->
    case gs:assq(Opt,Dict) of
	{value,V} -> [{Opt,V}|merge_opts(Opts,lists:keydelete(Opt,1,Dict))];
	false -> merge_opts(Opts,Dict)
    end.

the_config() ->
    Buttons=[button,checkbutton,radiobutton],
    AllPureTk = [Buttons,canvas,editor,entry,frame,label,listbox,
                 menubar,menubutton,scale,window],
    CanvasObj = [arc,image,line,oval,polygon,rectangle,text],
    All = [AllPureTk,CanvasObj,grid,gridline,menu,menuitem,gs],
    Containers = [canvas,frame,grid,menu,menubar,menubutton,menuitem,window],
    Ob1 = [Buttons,canvas,grid,frame,label,entry,editor,listbox,scale],
    Ob2 = [button,checkbutton,radiobutton,label,menubutton],
    Ob3 = [Buttons,frame,label,entry,editor,listbox,scale,menubutton,
	   menubar,menu],
    Ob4 = [canvas,editor,listbox],
    [{[Buttons,entry,scale,menubutton],enable,gen_enable,rw},
     {[Buttons,label,entry,scale,menubutton,menu],fg,gen_fg,rw},
     {[Buttons,label,entry,scale,menubutton,menu],bg,gen_bg,rw},
     {Ob1,anchor,gen_anchor,rw},
     {Ob1,height,gen_height,r},
     {Ob1--[frame],height,gen_height,w},
     {Ob1,width,gen_width,r},
     {Ob1--[frame],width,gen_width,w},
     {Ob1,pack_x,gen_pack_x,rw},
     {Ob1,pack_y,gen_pack_y,rw},
     {Ob1,pack_xy,gen_pack_xy,w},
     {Ob1,x,gen_x,rw},
     {Ob1,y,gen_y,rw},
     {Ob1,raise,gen_raise,w},
     {Ob1,lower,gen_lower,w},
     {Ob2,align,gen_align,rw},
     {Ob2,font,gen_font,rw},
     {Ob2,justify,gen_justify,rw},
     {Ob2,padx,gen_padx,rw},
     {Ob2,pady,gen_pady,rw},
     {Containers,default,gen_default,w},
     {[AllPureTk,menu],relief,gen_relief,rw},
     {[AllPureTk,menu],bw,gen_bw,rw},
     {[Buttons,canvas,frame,label,entry,scale,menubutton,menu,menubar],
      setfocus,gen_setfocus,rw},
     {Ob3,buttonpress,gen_buttonpress,rw},
     {Ob3,buttonrelease,gen_buttonrelease,rw},
     {Ob3,configure,gen_configure,rw},
     {[Ob3,window],destroy,gen_destroy,rw},
     {[Ob3,window],enter,gen_enter,rw},
     {[Ob3,window],leave,gen_leave,rw},
     {[Ob3,window],focus,gen_focus_ev,rw},
     {[Ob3,window],keypress,gen_keypress,rw},
     {[Ob3,window],keyrelease,gen_keyrelease,rw},
     {Ob3,motion,gen_motion,rw},
     %% events containing x,y are special
     {[window],buttonpress,gen_buttonpress,r},
     {[window],buttonrelease,gen_buttonrelease,r},
     {[window],motion,gen_motion,r},
     {All,font_wh,gen_font_wh,r},
     {All,choose_font,gen_choose_font,r},
     {All,data,gen_data,rw},
     {All,children,gen_children,r},
     {All,id,gen_id,r},
     {All,parent,gen_parent,r},
     {All,type,gen_type,r},
     {All,beep,gen_beep,w},
     {All,keep_opt,gen_keep_opt,w},
     {All,flush,gen_flush,rw},
     {AllPureTk,highlightbw,gen_highlightbw,rw},
     {AllPureTk,highlightbg,gen_highlightbg,rw},
     {AllPureTk,highlightfg,gen_highlightfg,rw},
     {AllPureTk,cursor,gen_cursor,rw}, % bug
     {[Buttons,label,menubutton],label,gen_label,rw},
     {[Buttons,menubutton,menu],activebg,gen_activebg,rw},
     {[Buttons,menubutton,menu],activefg,gen_activefg,rw},
     {[entry],selectbg,gen_selectbg,rw},
     {[entry],selectbw,gen_selectbw,rw},
     {[entry],selectfg,gen_selectfg,rw},
     {Ob4,activebg,gen_so_activebg,rw},
     {Ob4,bc,gen_so_bc,rw},
     {Ob4,bg,gen_so_bg,rw},
     {Ob4,hscroll,gen_so_hscroll,r},
     {Ob4,scrollbg,gen_so_scrollbg,rw},
     {Ob4,scrollfg,gen_so_scrollfg,rw},
     {Ob4,scrolls,gen_so_scrolls,w},
     {Ob4,selectbg,gen_so_selectbg,rw},
     {Ob4,selectbg,gen_so_selectbg,rw},
     {Ob4,selectbw,gen_so_selectbw,rw},
     {Ob4,selectbw,gen_so_selectbw,rw},
     {Ob4,selectfg,gen_so_selectfg,rw},
     {Ob4,selectfg,gen_so_selectfg,rw},
     {Ob4,vscroll,gen_so_vscroll,r},
     {CanvasObj,coords,gen_citem_coords,rw},
     {CanvasObj,lower,gen_citem_lower,w},
     {CanvasObj,raise,gen_citem_raise,w},
     {CanvasObj,move,gen_citem_move,w},
     {CanvasObj,setfocus,gen_citem_setfocus,rw},
     {CanvasObj,buttonpress,gen_citem_buttonpress,w}, % should be rw
     {CanvasObj,buttonrelease,gen_citem_buttonrelease,w},
     {CanvasObj,enter,gen_citem_enter,w},
     {CanvasObj,focus,gen_citem_setfocus,w},
     {CanvasObj,keypress,gen_citem_keypress,w},
     {CanvasObj,keyrelease,gen_citem_keyrelease,w},
     {CanvasObj,leave,gen_citem_leave,w},
     {CanvasObj,motion,gen_citem_motion,w},
     {CanvasObj,buttonpress,gen_buttonpress,r},
     {CanvasObj,buttonrelease,gen_buttonrelease,r},
     {CanvasObj,configure,gen_configure,r},
     {CanvasObj,destroy,gen_destroy,r},
     {CanvasObj,enter,gen_enter,r},
     {CanvasObj,leave,gen_leave,r},
     {CanvasObj,focus,gen_focus_ev,r},
     {CanvasObj,keypress,gen_keypress,r},
     {CanvasObj,keyrelease,gen_keyrelease,r},
     {CanvasObj,motion,gen_motion,r},
     {[arc,oval,polygon,rectangle],fill,gen_citem_fill,rw}].
