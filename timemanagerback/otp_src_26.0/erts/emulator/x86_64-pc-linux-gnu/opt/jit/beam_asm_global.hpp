/*
 *  Warning: Do not edit this file.
 *  Auto-generated by beam/jit/x86/beam_asm_global.hpp.pl.
 */

#ifndef _BEAM_ASM_GLOBAL_HPP
#define _BEAM_ASM_GLOBAL_HPP


class BeamGlobalAssembler : public BeamAssembler {
    typedef void (BeamGlobalAssembler::*emitFptr)(void);
    typedef void (*fptr)(void);

    enum GlobalLabels : uint32_t {
        apply_fun_shared,
        arith_compare_shared,
        arith_eq_shared,
        bif_nif_epilogue,
        bif_element_shared,
        bif_export_trap,
        bs_add_shared,
        bs_create_bin_error_shared,
        bs_size_check_shared,
        bs_get_tail_shared,
        bs_get_utf8_shared,
        bs_get_utf8_short_shared,
        call_bif_shared,
        call_light_bif_shared,
        call_nif_early,
        call_nif_shared,
        call_nif_yield_helper,
        catch_end_shared,
        check_float_error,
        construct_utf8_shared,
        dispatch_bif,
        dispatch_nif,
        dispatch_return,
        dispatch_save_calls_export,
        dispatch_save_calls_fun,
        export_trampoline,
        garbage_collect,
        generic_bp_global,
        generic_bp_local,
        get_sint64_shared,
        debug_bp,
        fconv_shared,
        handle_call_fun_error,
        handle_element_error,
        handle_hd_error,
        handle_map_get_badkey,
        handle_map_get_badmap,
        handle_map_size_error,
        handle_node_error,
        i_band_body_shared,
        i_band_guard_shared,
        i_bif_body_shared,
        i_bif_guard_shared,
        i_bor_body_shared,
        i_bor_guard_shared,
        i_bnot_body_shared,
        i_bnot_guard_shared,
        i_breakpoint_trampoline_shared,
        i_bsl_guard_shared,
        i_bsl_body_shared,
        i_bsr_guard_shared,
        i_bsr_body_shared,
        i_bxor_body_shared,
        i_bxor_guard_shared,
        i_func_info_shared,
        i_get_map_element_shared,
        i_get_map_element_hash_shared,
        i_load_nif_shared,
        i_length_guard_shared,
        i_length_body_shared,
        i_loop_rec_shared,
        i_test_yield_shared,
        int_div_rem_body_shared,
        int_div_rem_guard_shared,
        is_in_range_shared,
        is_ge_lt_shared,
        internal_hash_helper,
        minus_body_shared,
        minus_guard_shared,
        new_map_shared,
        plus_body_shared,
        plus_guard_shared,
        process_exit,
        process_main,
        raise_exception,
        raise_exception_shared,
        store_unaligned,
        times_body_shared,
        times_guard_shared,
        unary_minus_body_shared,
        unary_minus_guard_shared,
        unloaded_fun,
        update_map_assoc_shared,
        update_map_exact_guard_shared,
        update_map_exact_body_shared,

        context_switch,
        context_switch_simplified,
        do_schedule,

    };

    static const std::map<GlobalLabels, const std::string> labelNames;
    static const std::map<GlobalLabels, emitFptr> emitPtrs;
    std::unordered_map<GlobalLabels, Label> labels;
    std::unordered_map<GlobalLabels, fptr> ptrs;

    void emit_apply_fun_shared(void);
    void emit_arith_compare_shared(void);
    void emit_arith_eq_shared(void);
    void emit_bif_nif_epilogue(void);
    void emit_bif_element_shared(void);
    void emit_bif_export_trap(void);
    void emit_bs_add_shared(void);
    void emit_bs_create_bin_error_shared(void);
    void emit_bs_size_check_shared(void);
    void emit_bs_get_tail_shared(void);
    void emit_bs_get_utf8_shared(void);
    void emit_bs_get_utf8_short_shared(void);
    void emit_call_bif_shared(void);
    void emit_call_light_bif_shared(void);
    void emit_call_nif_early(void);
    void emit_call_nif_shared(void);
    void emit_call_nif_yield_helper(void);
    void emit_catch_end_shared(void);
    void emit_check_float_error(void);
    void emit_construct_utf8_shared(void);
    void emit_dispatch_bif(void);
    void emit_dispatch_nif(void);
    void emit_dispatch_return(void);
    void emit_dispatch_save_calls_export(void);
    void emit_dispatch_save_calls_fun(void);
    void emit_export_trampoline(void);
    void emit_garbage_collect(void);
    void emit_generic_bp_global(void);
    void emit_generic_bp_local(void);
    void emit_get_sint64_shared(void);
    void emit_debug_bp(void);
    void emit_fconv_shared(void);
    void emit_handle_call_fun_error(void);
    void emit_handle_element_error(void);
    void emit_handle_hd_error(void);
    void emit_handle_map_get_badkey(void);
    void emit_handle_map_get_badmap(void);
    void emit_handle_map_size_error(void);
    void emit_handle_node_error(void);
    void emit_i_band_body_shared(void);
    void emit_i_band_guard_shared(void);
    void emit_i_bif_body_shared(void);
    void emit_i_bif_guard_shared(void);
    void emit_i_bor_body_shared(void);
    void emit_i_bor_guard_shared(void);
    void emit_i_bnot_body_shared(void);
    void emit_i_bnot_guard_shared(void);
    void emit_i_breakpoint_trampoline_shared(void);
    void emit_i_bsl_guard_shared(void);
    void emit_i_bsl_body_shared(void);
    void emit_i_bsr_guard_shared(void);
    void emit_i_bsr_body_shared(void);
    void emit_i_bxor_body_shared(void);
    void emit_i_bxor_guard_shared(void);
    void emit_i_func_info_shared(void);
    void emit_i_get_map_element_shared(void);
    void emit_i_get_map_element_hash_shared(void);
    void emit_i_load_nif_shared(void);
    void emit_i_length_guard_shared(void);
    void emit_i_length_body_shared(void);
    void emit_i_loop_rec_shared(void);
    void emit_i_test_yield_shared(void);
    void emit_int_div_rem_body_shared(void);
    void emit_int_div_rem_guard_shared(void);
    void emit_is_in_range_shared(void);
    void emit_is_ge_lt_shared(void);
    void emit_internal_hash_helper(void);
    void emit_minus_body_shared(void);
    void emit_minus_guard_shared(void);
    void emit_new_map_shared(void);
    void emit_plus_body_shared(void);
    void emit_plus_guard_shared(void);
    void emit_process_exit(void);
    void emit_process_main(void);
    void emit_raise_exception(void);
    void emit_raise_exception_shared(void);
    void emit_store_unaligned(void);
    void emit_times_body_shared(void);
    void emit_times_guard_shared(void);
    void emit_unary_minus_body_shared(void);
    void emit_unary_minus_guard_shared(void);
    void emit_unloaded_fun(void);
    void emit_update_map_assoc_shared(void);
    void emit_update_map_exact_guard_shared(void);
    void emit_update_map_exact_body_shared(void);


    template<typename T>
    void emit_bitwise_fallback_body(T(*func_ptr), const ErtsCodeMFA *mfa);

    template<typename T>
    void emit_bitwise_fallback_guard(T(*func_ptr));

    x86::Mem emit_i_length_common(Label fail, int state_size);

    void emit_flatmap_get_element();
    void emit_hashmap_get_element();

public:
    BeamGlobalAssembler(JitAllocator *allocator);

    void (*get(GlobalLabels lbl))(void) {
        ASSERT(ptrs[lbl]);
        return ptrs[lbl];
    }

    void (*get_apply_fun_shared(void))() { return get(apply_fun_shared); }
    void (*get_arith_compare_shared(void))() { return get(arith_compare_shared); }
    void (*get_arith_eq_shared(void))() { return get(arith_eq_shared); }
    void (*get_bif_nif_epilogue(void))() { return get(bif_nif_epilogue); }
    void (*get_bif_element_shared(void))() { return get(bif_element_shared); }
    void (*get_bif_export_trap(void))() { return get(bif_export_trap); }
    void (*get_bs_add_shared(void))() { return get(bs_add_shared); }
    void (*get_bs_create_bin_error_shared(void))() { return get(bs_create_bin_error_shared); }
    void (*get_bs_size_check_shared(void))() { return get(bs_size_check_shared); }
    void (*get_bs_get_tail_shared(void))() { return get(bs_get_tail_shared); }
    void (*get_bs_get_utf8_shared(void))() { return get(bs_get_utf8_shared); }
    void (*get_bs_get_utf8_short_shared(void))() { return get(bs_get_utf8_short_shared); }
    void (*get_call_bif_shared(void))() { return get(call_bif_shared); }
    void (*get_call_light_bif_shared(void))() { return get(call_light_bif_shared); }
    void (*get_call_nif_early(void))() { return get(call_nif_early); }
    void (*get_call_nif_shared(void))() { return get(call_nif_shared); }
    void (*get_call_nif_yield_helper(void))() { return get(call_nif_yield_helper); }
    void (*get_catch_end_shared(void))() { return get(catch_end_shared); }
    void (*get_check_float_error(void))() { return get(check_float_error); }
    void (*get_construct_utf8_shared(void))() { return get(construct_utf8_shared); }
    void (*get_dispatch_bif(void))() { return get(dispatch_bif); }
    void (*get_dispatch_nif(void))() { return get(dispatch_nif); }
    void (*get_dispatch_return(void))() { return get(dispatch_return); }
    void (*get_dispatch_save_calls_export(void))() { return get(dispatch_save_calls_export); }
    void (*get_dispatch_save_calls_fun(void))() { return get(dispatch_save_calls_fun); }
    void (*get_export_trampoline(void))() { return get(export_trampoline); }
    void (*get_garbage_collect(void))() { return get(garbage_collect); }
    void (*get_generic_bp_global(void))() { return get(generic_bp_global); }
    void (*get_generic_bp_local(void))() { return get(generic_bp_local); }
    void (*get_get_sint64_shared(void))() { return get(get_sint64_shared); }
    void (*get_debug_bp(void))() { return get(debug_bp); }
    void (*get_fconv_shared(void))() { return get(fconv_shared); }
    void (*get_handle_call_fun_error(void))() { return get(handle_call_fun_error); }
    void (*get_handle_element_error(void))() { return get(handle_element_error); }
    void (*get_handle_hd_error(void))() { return get(handle_hd_error); }
    void (*get_handle_map_get_badkey(void))() { return get(handle_map_get_badkey); }
    void (*get_handle_map_get_badmap(void))() { return get(handle_map_get_badmap); }
    void (*get_handle_map_size_error(void))() { return get(handle_map_size_error); }
    void (*get_handle_node_error(void))() { return get(handle_node_error); }
    void (*get_i_band_body_shared(void))() { return get(i_band_body_shared); }
    void (*get_i_band_guard_shared(void))() { return get(i_band_guard_shared); }
    void (*get_i_bif_body_shared(void))() { return get(i_bif_body_shared); }
    void (*get_i_bif_guard_shared(void))() { return get(i_bif_guard_shared); }
    void (*get_i_bor_body_shared(void))() { return get(i_bor_body_shared); }
    void (*get_i_bor_guard_shared(void))() { return get(i_bor_guard_shared); }
    void (*get_i_bnot_body_shared(void))() { return get(i_bnot_body_shared); }
    void (*get_i_bnot_guard_shared(void))() { return get(i_bnot_guard_shared); }
    void (*get_i_breakpoint_trampoline_shared(void))() { return get(i_breakpoint_trampoline_shared); }
    void (*get_i_bsl_guard_shared(void))() { return get(i_bsl_guard_shared); }
    void (*get_i_bsl_body_shared(void))() { return get(i_bsl_body_shared); }
    void (*get_i_bsr_guard_shared(void))() { return get(i_bsr_guard_shared); }
    void (*get_i_bsr_body_shared(void))() { return get(i_bsr_body_shared); }
    void (*get_i_bxor_body_shared(void))() { return get(i_bxor_body_shared); }
    void (*get_i_bxor_guard_shared(void))() { return get(i_bxor_guard_shared); }
    void (*get_i_func_info_shared(void))() { return get(i_func_info_shared); }
    void (*get_i_get_map_element_shared(void))() { return get(i_get_map_element_shared); }
    void (*get_i_get_map_element_hash_shared(void))() { return get(i_get_map_element_hash_shared); }
    void (*get_i_load_nif_shared(void))() { return get(i_load_nif_shared); }
    void (*get_i_length_guard_shared(void))() { return get(i_length_guard_shared); }
    void (*get_i_length_body_shared(void))() { return get(i_length_body_shared); }
    void (*get_i_loop_rec_shared(void))() { return get(i_loop_rec_shared); }
    void (*get_i_test_yield_shared(void))() { return get(i_test_yield_shared); }
    void (*get_int_div_rem_body_shared(void))() { return get(int_div_rem_body_shared); }
    void (*get_int_div_rem_guard_shared(void))() { return get(int_div_rem_guard_shared); }
    void (*get_is_in_range_shared(void))() { return get(is_in_range_shared); }
    void (*get_is_ge_lt_shared(void))() { return get(is_ge_lt_shared); }
    void (*get_internal_hash_helper(void))() { return get(internal_hash_helper); }
    void (*get_minus_body_shared(void))() { return get(minus_body_shared); }
    void (*get_minus_guard_shared(void))() { return get(minus_guard_shared); }
    void (*get_new_map_shared(void))() { return get(new_map_shared); }
    void (*get_plus_body_shared(void))() { return get(plus_body_shared); }
    void (*get_plus_guard_shared(void))() { return get(plus_guard_shared); }
    void (*get_process_exit(void))() { return get(process_exit); }
    void (*get_process_main(void))() { return get(process_main); }
    void (*get_raise_exception(void))() { return get(raise_exception); }
    void (*get_raise_exception_shared(void))() { return get(raise_exception_shared); }
    void (*get_store_unaligned(void))() { return get(store_unaligned); }
    void (*get_times_body_shared(void))() { return get(times_body_shared); }
    void (*get_times_guard_shared(void))() { return get(times_guard_shared); }
    void (*get_unary_minus_body_shared(void))() { return get(unary_minus_body_shared); }
    void (*get_unary_minus_guard_shared(void))() { return get(unary_minus_guard_shared); }
    void (*get_unloaded_fun(void))() { return get(unloaded_fun); }
    void (*get_update_map_assoc_shared(void))() { return get(update_map_assoc_shared); }
    void (*get_update_map_exact_guard_shared(void))() { return get(update_map_exact_guard_shared); }
    void (*get_update_map_exact_body_shared(void))() { return get(update_map_exact_body_shared); }

    void (*get_context_switch(void))() { return get(context_switch); }
    void (*get_context_switch_simplified(void))() { return get(context_switch_simplified); }
    void (*get_do_schedule(void))() { return get(do_schedule); }

};

#ifdef ERTS_BEAM_ASM_GLOBAL_WANT_STATIC_DEFS

const std::map<BeamGlobalAssembler::GlobalLabels, BeamGlobalAssembler::emitFptr>
BeamGlobalAssembler::emitPtrs = {
    {apply_fun_shared, &BeamGlobalAssembler::emit_apply_fun_shared},
    {arith_compare_shared, &BeamGlobalAssembler::emit_arith_compare_shared},
    {arith_eq_shared, &BeamGlobalAssembler::emit_arith_eq_shared},
    {bif_nif_epilogue, &BeamGlobalAssembler::emit_bif_nif_epilogue},
    {bif_element_shared, &BeamGlobalAssembler::emit_bif_element_shared},
    {bif_export_trap, &BeamGlobalAssembler::emit_bif_export_trap},
    {bs_add_shared, &BeamGlobalAssembler::emit_bs_add_shared},
    {bs_create_bin_error_shared, &BeamGlobalAssembler::emit_bs_create_bin_error_shared},
    {bs_size_check_shared, &BeamGlobalAssembler::emit_bs_size_check_shared},
    {bs_get_tail_shared, &BeamGlobalAssembler::emit_bs_get_tail_shared},
    {bs_get_utf8_shared, &BeamGlobalAssembler::emit_bs_get_utf8_shared},
    {bs_get_utf8_short_shared, &BeamGlobalAssembler::emit_bs_get_utf8_short_shared},
    {call_bif_shared, &BeamGlobalAssembler::emit_call_bif_shared},
    {call_light_bif_shared, &BeamGlobalAssembler::emit_call_light_bif_shared},
    {call_nif_early, &BeamGlobalAssembler::emit_call_nif_early},
    {call_nif_shared, &BeamGlobalAssembler::emit_call_nif_shared},
    {call_nif_yield_helper, &BeamGlobalAssembler::emit_call_nif_yield_helper},
    {catch_end_shared, &BeamGlobalAssembler::emit_catch_end_shared},
    {check_float_error, &BeamGlobalAssembler::emit_check_float_error},
    {construct_utf8_shared, &BeamGlobalAssembler::emit_construct_utf8_shared},
    {dispatch_bif, &BeamGlobalAssembler::emit_dispatch_bif},
    {dispatch_nif, &BeamGlobalAssembler::emit_dispatch_nif},
    {dispatch_return, &BeamGlobalAssembler::emit_dispatch_return},
    {dispatch_save_calls_export, &BeamGlobalAssembler::emit_dispatch_save_calls_export},
    {dispatch_save_calls_fun, &BeamGlobalAssembler::emit_dispatch_save_calls_fun},
    {export_trampoline, &BeamGlobalAssembler::emit_export_trampoline},
    {garbage_collect, &BeamGlobalAssembler::emit_garbage_collect},
    {generic_bp_global, &BeamGlobalAssembler::emit_generic_bp_global},
    {generic_bp_local, &BeamGlobalAssembler::emit_generic_bp_local},
    {get_sint64_shared, &BeamGlobalAssembler::emit_get_sint64_shared},
    {debug_bp, &BeamGlobalAssembler::emit_debug_bp},
    {fconv_shared, &BeamGlobalAssembler::emit_fconv_shared},
    {handle_call_fun_error, &BeamGlobalAssembler::emit_handle_call_fun_error},
    {handle_element_error, &BeamGlobalAssembler::emit_handle_element_error},
    {handle_hd_error, &BeamGlobalAssembler::emit_handle_hd_error},
    {handle_map_get_badkey, &BeamGlobalAssembler::emit_handle_map_get_badkey},
    {handle_map_get_badmap, &BeamGlobalAssembler::emit_handle_map_get_badmap},
    {handle_map_size_error, &BeamGlobalAssembler::emit_handle_map_size_error},
    {handle_node_error, &BeamGlobalAssembler::emit_handle_node_error},
    {i_band_body_shared, &BeamGlobalAssembler::emit_i_band_body_shared},
    {i_band_guard_shared, &BeamGlobalAssembler::emit_i_band_guard_shared},
    {i_bif_body_shared, &BeamGlobalAssembler::emit_i_bif_body_shared},
    {i_bif_guard_shared, &BeamGlobalAssembler::emit_i_bif_guard_shared},
    {i_bor_body_shared, &BeamGlobalAssembler::emit_i_bor_body_shared},
    {i_bor_guard_shared, &BeamGlobalAssembler::emit_i_bor_guard_shared},
    {i_bnot_body_shared, &BeamGlobalAssembler::emit_i_bnot_body_shared},
    {i_bnot_guard_shared, &BeamGlobalAssembler::emit_i_bnot_guard_shared},
    {i_breakpoint_trampoline_shared, &BeamGlobalAssembler::emit_i_breakpoint_trampoline_shared},
    {i_bsl_guard_shared, &BeamGlobalAssembler::emit_i_bsl_guard_shared},
    {i_bsl_body_shared, &BeamGlobalAssembler::emit_i_bsl_body_shared},
    {i_bsr_guard_shared, &BeamGlobalAssembler::emit_i_bsr_guard_shared},
    {i_bsr_body_shared, &BeamGlobalAssembler::emit_i_bsr_body_shared},
    {i_bxor_body_shared, &BeamGlobalAssembler::emit_i_bxor_body_shared},
    {i_bxor_guard_shared, &BeamGlobalAssembler::emit_i_bxor_guard_shared},
    {i_func_info_shared, &BeamGlobalAssembler::emit_i_func_info_shared},
    {i_get_map_element_shared, &BeamGlobalAssembler::emit_i_get_map_element_shared},
    {i_get_map_element_hash_shared, &BeamGlobalAssembler::emit_i_get_map_element_hash_shared},
    {i_load_nif_shared, &BeamGlobalAssembler::emit_i_load_nif_shared},
    {i_length_guard_shared, &BeamGlobalAssembler::emit_i_length_guard_shared},
    {i_length_body_shared, &BeamGlobalAssembler::emit_i_length_body_shared},
    {i_loop_rec_shared, &BeamGlobalAssembler::emit_i_loop_rec_shared},
    {i_test_yield_shared, &BeamGlobalAssembler::emit_i_test_yield_shared},
    {int_div_rem_body_shared, &BeamGlobalAssembler::emit_int_div_rem_body_shared},
    {int_div_rem_guard_shared, &BeamGlobalAssembler::emit_int_div_rem_guard_shared},
    {is_in_range_shared, &BeamGlobalAssembler::emit_is_in_range_shared},
    {is_ge_lt_shared, &BeamGlobalAssembler::emit_is_ge_lt_shared},
    {internal_hash_helper, &BeamGlobalAssembler::emit_internal_hash_helper},
    {minus_body_shared, &BeamGlobalAssembler::emit_minus_body_shared},
    {minus_guard_shared, &BeamGlobalAssembler::emit_minus_guard_shared},
    {new_map_shared, &BeamGlobalAssembler::emit_new_map_shared},
    {plus_body_shared, &BeamGlobalAssembler::emit_plus_body_shared},
    {plus_guard_shared, &BeamGlobalAssembler::emit_plus_guard_shared},
    {process_exit, &BeamGlobalAssembler::emit_process_exit},
    {process_main, &BeamGlobalAssembler::emit_process_main},
    {raise_exception, &BeamGlobalAssembler::emit_raise_exception},
    {raise_exception_shared, &BeamGlobalAssembler::emit_raise_exception_shared},
    {store_unaligned, &BeamGlobalAssembler::emit_store_unaligned},
    {times_body_shared, &BeamGlobalAssembler::emit_times_body_shared},
    {times_guard_shared, &BeamGlobalAssembler::emit_times_guard_shared},
    {unary_minus_body_shared, &BeamGlobalAssembler::emit_unary_minus_body_shared},
    {unary_minus_guard_shared, &BeamGlobalAssembler::emit_unary_minus_guard_shared},
    {unloaded_fun, &BeamGlobalAssembler::emit_unloaded_fun},
    {update_map_assoc_shared, &BeamGlobalAssembler::emit_update_map_assoc_shared},
    {update_map_exact_guard_shared, &BeamGlobalAssembler::emit_update_map_exact_guard_shared},
    {update_map_exact_body_shared, &BeamGlobalAssembler::emit_update_map_exact_body_shared},

};

const std::map<BeamGlobalAssembler::GlobalLabels, const std::string>
BeamGlobalAssembler::labelNames = {
    {apply_fun_shared, "apply_fun_shared"},
    {arith_compare_shared, "arith_compare_shared"},
    {arith_eq_shared, "arith_eq_shared"},
    {bif_nif_epilogue, "bif_nif_epilogue"},
    {bif_element_shared, "bif_element_shared"},
    {bif_export_trap, "bif_export_trap"},
    {bs_add_shared, "bs_add_shared"},
    {bs_create_bin_error_shared, "bs_create_bin_error_shared"},
    {bs_size_check_shared, "bs_size_check_shared"},
    {bs_get_tail_shared, "bs_get_tail_shared"},
    {bs_get_utf8_shared, "bs_get_utf8_shared"},
    {bs_get_utf8_short_shared, "bs_get_utf8_short_shared"},
    {call_bif_shared, "call_bif_shared"},
    {call_light_bif_shared, "call_light_bif_shared"},
    {call_nif_early, "call_nif_early"},
    {call_nif_shared, "call_nif_shared"},
    {call_nif_yield_helper, "call_nif_yield_helper"},
    {catch_end_shared, "catch_end_shared"},
    {check_float_error, "check_float_error"},
    {construct_utf8_shared, "construct_utf8_shared"},
    {dispatch_bif, "dispatch_bif"},
    {dispatch_nif, "dispatch_nif"},
    {dispatch_return, "dispatch_return"},
    {dispatch_save_calls_export, "dispatch_save_calls_export"},
    {dispatch_save_calls_fun, "dispatch_save_calls_fun"},
    {export_trampoline, "export_trampoline"},
    {garbage_collect, "garbage_collect"},
    {generic_bp_global, "generic_bp_global"},
    {generic_bp_local, "generic_bp_local"},
    {get_sint64_shared, "get_sint64_shared"},
    {debug_bp, "debug_bp"},
    {fconv_shared, "fconv_shared"},
    {handle_call_fun_error, "handle_call_fun_error"},
    {handle_element_error, "handle_element_error"},
    {handle_hd_error, "handle_hd_error"},
    {handle_map_get_badkey, "handle_map_get_badkey"},
    {handle_map_get_badmap, "handle_map_get_badmap"},
    {handle_map_size_error, "handle_map_size_error"},
    {handle_node_error, "handle_node_error"},
    {i_band_body_shared, "i_band_body_shared"},
    {i_band_guard_shared, "i_band_guard_shared"},
    {i_bif_body_shared, "i_bif_body_shared"},
    {i_bif_guard_shared, "i_bif_guard_shared"},
    {i_bor_body_shared, "i_bor_body_shared"},
    {i_bor_guard_shared, "i_bor_guard_shared"},
    {i_bnot_body_shared, "i_bnot_body_shared"},
    {i_bnot_guard_shared, "i_bnot_guard_shared"},
    {i_breakpoint_trampoline_shared, "i_breakpoint_trampoline_shared"},
    {i_bsl_guard_shared, "i_bsl_guard_shared"},
    {i_bsl_body_shared, "i_bsl_body_shared"},
    {i_bsr_guard_shared, "i_bsr_guard_shared"},
    {i_bsr_body_shared, "i_bsr_body_shared"},
    {i_bxor_body_shared, "i_bxor_body_shared"},
    {i_bxor_guard_shared, "i_bxor_guard_shared"},
    {i_func_info_shared, "i_func_info_shared"},
    {i_get_map_element_shared, "i_get_map_element_shared"},
    {i_get_map_element_hash_shared, "i_get_map_element_hash_shared"},
    {i_load_nif_shared, "i_load_nif_shared"},
    {i_length_guard_shared, "i_length_guard_shared"},
    {i_length_body_shared, "i_length_body_shared"},
    {i_loop_rec_shared, "i_loop_rec_shared"},
    {i_test_yield_shared, "i_test_yield_shared"},
    {int_div_rem_body_shared, "int_div_rem_body_shared"},
    {int_div_rem_guard_shared, "int_div_rem_guard_shared"},
    {is_in_range_shared, "is_in_range_shared"},
    {is_ge_lt_shared, "is_ge_lt_shared"},
    {internal_hash_helper, "internal_hash_helper"},
    {minus_body_shared, "minus_body_shared"},
    {minus_guard_shared, "minus_guard_shared"},
    {new_map_shared, "new_map_shared"},
    {plus_body_shared, "plus_body_shared"},
    {plus_guard_shared, "plus_guard_shared"},
    {process_exit, "process_exit"},
    {process_main, "process_main"},
    {raise_exception, "raise_exception"},
    {raise_exception_shared, "raise_exception_shared"},
    {store_unaligned, "store_unaligned"},
    {times_body_shared, "times_body_shared"},
    {times_guard_shared, "times_guard_shared"},
    {unary_minus_body_shared, "unary_minus_body_shared"},
    {unary_minus_guard_shared, "unary_minus_guard_shared"},
    {unloaded_fun, "unloaded_fun"},
    {update_map_assoc_shared, "update_map_assoc_shared"},
    {update_map_exact_guard_shared, "update_map_exact_guard_shared"},
    {update_map_exact_body_shared, "update_map_exact_body_shared"},

    {context_switch, "context_switch"},
    {context_switch_simplified, "context_switch_simplified"},
    {do_schedule, "do_schedule"},

};

#endif /* ERTS_BEAM_ASM_GLOBAL_WANT_STATIC_DEFS */

#endif /* !_BEAM_ASM_GLOBAL_HPP */
