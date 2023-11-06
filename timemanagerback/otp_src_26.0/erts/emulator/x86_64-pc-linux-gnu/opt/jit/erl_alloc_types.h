/*
 * -----------------------------------------------------------------------
 *
 * NOTE: Do *not* edit this file; instead, edit 'erl_alloc.types' and
 *       build again! It was automatically generated by 'make_alloc_types'.
 *
 * -----------------------------------------------------------------------
 *
 * 
 * Copyright Ericsson AB 2023. All Rights Reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#ifndef ERL_ALLOC_TYPES_H__
#define ERL_ALLOC_TYPES_H__


/* --- Allocator numbers -------------------------------------------------- */

#define ERTS_ALC_A_INVALID (0)

#define ERTS_ALC_A_MIN (1)

#define ERTS_ALC_A_SYSTEM (1)
#define ERTS_ALC_A_TEMPORARY (2)
#define ERTS_ALC_A_SHORT_LIVED (3)
#define ERTS_ALC_A_STANDARD (4)
#define ERTS_ALC_A_LONG_LIVED (5)
#define ERTS_ALC_A_EHEAP (6)
#define ERTS_ALC_A_ETS (7)
#define ERTS_ALC_A_FIXED_SIZE (8)
#define ERTS_ALC_A_LITERAL (9)
#define ERTS_ALC_A_BINARY (10)
#define ERTS_ALC_A_DRIVER (11)
#define ERTS_ALC_A_TEST (12)

#define ERTS_ALC_A_MAX (12)

#define ERTS_ALC_A_COUNT (ERTS_ALC_A_MAX - ERTS_ALC_A_MIN + 1)


/* --- Class numbers ------------------------------------------------------ */

#define ERTS_ALC_C_INVALID (0)

#define ERTS_ALC_C_MIN (1)

#define ERTS_ALC_C_ATOM  (1)
#define ERTS_ALC_C_BINARIES  (2)
#define ERTS_ALC_C_CODE  (3)
#define ERTS_ALC_C_ETS  (4)
#define ERTS_ALC_C_PROCESSES  (5)
#define ERTS_ALC_C_SYSTEM  (6)

#define ERTS_ALC_C_MAX (6)

#define ERTS_ALC_C_COUNT (ERTS_ALC_C_MAX - ERTS_ALC_C_MIN + 1)


/* --- Type number intervals ---------------------------------------------- */

#define ERTS_ALC_N_INVALID (0)

#define ERTS_ALC_N_MIN (1)

/* Type numbers used for sys_alloc */
#define ERTS_ALC_N_MIN_A_SYSTEM (1)
#define ERTS_ALC_N_MAX_A_SYSTEM (4)

/* Type numbers used for temp_alloc */
#define ERTS_ALC_N_MIN_A_TEMPORARY (5)
#define ERTS_ALC_N_MAX_A_TEMPORARY (21)

/* Type numbers used for sl_alloc */
#define ERTS_ALC_N_MIN_A_SHORT_LIVED (22)
#define ERTS_ALC_N_MAX_A_SHORT_LIVED (91)

/* Type numbers used for std_alloc */
#define ERTS_ALC_N_MIN_A_STANDARD (92)
#define ERTS_ALC_N_MAX_A_STANDARD (137)

/* Type numbers used for ll_alloc */
#define ERTS_ALC_N_MIN_A_LONG_LIVED (138)
#define ERTS_ALC_N_MAX_A_LONG_LIVED (182)

/* Type numbers used for eheap_alloc */
#define ERTS_ALC_N_MIN_A_EHEAP (183)
#define ERTS_ALC_N_MAX_A_EHEAP (187)

/* Type numbers used for ets_alloc */
#define ERTS_ALC_N_MIN_A_ETS (188)
#define ERTS_ALC_N_MAX_A_ETS (196)

/* Type numbers used for fix_alloc */
#define ERTS_ALC_N_MIN_A_FIXED_SIZE (197)
#define ERTS_ALC_N_MAX_A_FIXED_SIZE (211)

/* Type numbers used for literal_alloc */
#define ERTS_ALC_N_MIN_A_LITERAL (212)
#define ERTS_ALC_N_MAX_A_LITERAL (212)

/* Type numbers used for binary_alloc */
#define ERTS_ALC_N_MIN_A_BINARY (213)
#define ERTS_ALC_N_MAX_A_BINARY (214)

/* Type numbers used for driver_alloc */
#define ERTS_ALC_N_MIN_A_DRIVER (215)
#define ERTS_ALC_N_MAX_A_DRIVER (229)

/* Type numbers used for test_alloc */
#define ERTS_ALC_N_MIN_A_TEST (230)
#define ERTS_ALC_N_MAX_A_TEST (230)

#define ERTS_ALC_N_MAX (230)

#define ERTS_ALC_N_COUNT (ERTS_ALC_N_MAX - ERTS_ALC_N_MIN + 1)


/* --- Multi thread use of allocators -------------------------------------- */

#define ERTS_ALC_MTA_SYSTEM (1)
#define ERTS_ALC_MTA_TEMPORARY (1)
#define ERTS_ALC_MTA_SHORT_LIVED (1)
#define ERTS_ALC_MTA_STANDARD (1)
#define ERTS_ALC_MTA_LONG_LIVED (1)
#define ERTS_ALC_MTA_EHEAP (1)
#define ERTS_ALC_MTA_ETS (1)
#define ERTS_ALC_MTA_FIXED_SIZE (1)
#define ERTS_ALC_MTA_LITERAL (1)
#define ERTS_ALC_MTA_BINARY (1)
#define ERTS_ALC_MTA_DRIVER (1)
#define ERTS_ALC_MTA_TEST (1)


/* --- Types --------------------------------------------------------------- */

typedef Uint32 ErtsAlcType_t; /* The type used for memory types */

#define ERTS_ALC_T_INVALID (0)

#define ERTS_ALC_T_UNDEF (225)
#define ERTS_ALC_T_NBIF_TABLE (353)
#define ERTS_ALC_T_INFO_DSBUF (481)
#define ERTS_ALC_T_ENVIRONMENT (609)
#define ERTS_ALC_T_TMP_HEAP (722)
#define ERTS_ALC_T_ROOTSET (850)
#define ERTS_ALC_T_LOADER_TMP (946)
#define ERTS_ALC_T_NC_TMP (1122)
#define ERTS_ALC_T_TMP (1250)
#define ERTS_ALC_T_DCTRL_BUF (1378)
#define ERTS_ALC_T_ESTACK (1506)
#define ERTS_ALC_T_DB_TMP (1602)
#define ERTS_ALC_T_DB_MC_STK (1730)
#define ERTS_ALC_T_DB_MS_CMPL_HEAP (1858)
#define ERTS_ALC_T_LOGGER_DSBUF (2018)
#define ERTS_ALC_T_TMP_DSBUF (2146)
#define ERTS_ALC_T_DDLL_TMP_BUF (2274)
#define ERTS_ALC_T_RE_TMP_BUF (2402)
#define ERTS_ALC_T_TEMP_TERM (2530)
#define ERTS_ALC_T_SYS_READ_BUF (2658)
#define ERTS_ALC_T_SYS_WRITE_BUF (2786)
#define ERTS_ALC_T_PROC_LIST (2899)
#define ERTS_ALC_T_SAVED_ESTACK (3027)
#define ERTS_ALC_T_MSGQ_CHNG (3155)
#define ERTS_ALC_T_PREPARED_CODE (3251)
#define ERTS_ALC_T_TIMER_REQUEST (3411)
#define ERTS_ALC_T_BTM_YIELD_STATE (3539)
#define ERTS_ALC_T_DB_FIXATION (3651)
#define ERTS_ALC_T_DB_FIX_DEL (3779)
#define ERTS_ALC_T_DB_MS_RUN_HEAP (3907)
#define ERTS_ALC_T_DB_PROC_CLEANUP (4035)
#define ERTS_ALC_T_ETS_ALL_REQ (4163)
#define ERTS_ALC_T_ETS_I_LST_TRAP (4291)
#define ERTS_ALC_T_PORT_TASK (4451)
#define ERTS_ALC_T_PT_HNDL_LIST (4579)
#define ERTS_ALC_T_MISC_OP_LIST (4707)
#define ERTS_ALC_T_PORT_NAMES (4835)
#define ERTS_ALC_T_PTAB_LIST_DEL (4947)
#define ERTS_ALC_T_PTAB_LIST_CNKI (5075)
#define ERTS_ALC_T_PTAB_LIST_PIDS (5203)
#define ERTS_ALC_T_RE_SUBJECT (5347)
#define ERTS_ALC_T_RE_STACK (5475)
#define ERTS_ALC_T_UNICODE_BUFFER (5603)
#define ERTS_ALC_T_BINARY_BUFFER (5731)
#define ERTS_ALC_T_TMP_CPU_IDS (5859)
#define ERTS_ALC_T_EXT_TERM_DATA (5971)
#define ERTS_ALC_T_CODE_IX_LOCK_Q (6115)
#define ERTS_ALC_T_BUSY_CALLER_TAB (6243)
#define ERTS_ALC_T_BUSY_CALLER (6371)
#define ERTS_ALC_T_PROC_SYS_TSK (6483)
#define ERTS_ALC_T_PROC_SYS_TSK_QS (6611)
#define ERTS_ALC_T_NEW_TIME_OFFSET (6755)
#define ERTS_ALC_T_IOB_REQ (6883)
#define ERTS_ALC_T_TRACE_MSG_QUEUE (7011)
#define ERTS_ALC_T_DIRTY_SL (7139)
#define ERTS_ALC_T_BINARY_FIND (7251)
#define ERTS_ALC_T_DIST_TRANSCODE (7395)
#define ERTS_ALC_T_MISC_AUX_WORK (7523)
#define ERTS_ALC_T_THR_Q_SL (7651)
#define ERTS_ALC_T_ASYNC (7779)
#define ERTS_ALC_T_XPORTS_LIST (7907)
#define ERTS_ALC_T_T_THR_PRGR_DATA (8035)
#define ERTS_ALC_T_RELEASE_LAREA (8163)
#define ERTS_ALC_T_SIG_DATA (8275)
#define ERTS_ALC_T_SIG_YIELD_DATA (8403)
#define ERTS_ALC_T_DIST_DEMONITOR (8531)
#define ERTS_ALC_T_CML_CLEANUP (8675)
#define ERTS_ALC_T_ML_YIELD_STATE (8803)
#define ERTS_ALC_T_PF3_ARGS (8915)
#define ERTS_ALC_T_SETUP_CONN_ARG (9043)
#define ERTS_ALC_T_LIST_TRAP (9171)
#define ERTS_ALC_T_CONT_EXIT_TRAP (9299)
#define ERTS_ALC_T_SEQ_YIELD_STATE (9443)
#define ERTS_ALC_T_PHASH2_TRAP (9555)
#define ERTS_ALC_T_MAP_TRAP (9683)
#define ERTS_ALC_T_PERSISTENT_LOCK_Q (9827)
#define ERTS_ALC_T_PERSISTENT_TERM_TMP (9955)
#define ERTS_ALC_T_T2B_VEC (10067)
#define ERTS_ALC_T_ETHR_SL (10211)
#define ERTS_ALC_T_SYS_MSG_Q (10323)
#define ERTS_ALC_T_SL_MPATHS (10467)
#define ERTS_ALC_T_T2B_DETERMINISTIC (10579)
#define ERTS_ALC_T_DEBUG (10723)
#define ERTS_ALC_T_LITERAL_REF (10803)
#define ERTS_ALC_T_PURGE_DATA (10931)
#define ERTS_ALC_T_AINFO_REQ (11107)
#define ERTS_ALC_T_SCHED_WTIME_REQ (11235)
#define ERTS_ALC_T_GC_INFO_REQ (11363)
#define ERTS_ALC_T_SYS_CHECK_REQ (11491)
#define ERTS_ALC_T_SHORT_LIVED_TERM (11619)
#define ERTS_ALC_T_POLLSET_UPDREQ (11747)
#define ERTS_ALC_T_REG_PROC (11860)
#define ERTS_ALC_T_REG_TABLE (12004)
#define ERTS_ALC_T_FUN_TABLE (12084)
#define ERTS_ALC_T_DIST_TABLE (12260)
#define ERTS_ALC_T_NODE_TABLE (12388)
#define ERTS_ALC_T_MODULE_REFS (12468)
#define ERTS_ALC_T_NC_STD (12644)
#define ERTS_ALC_T_DCACHE (12772)
#define ERTS_ALC_T_DIST_ENTRY (12900)
#define ERTS_ALC_T_NODE_ENTRY (13028)
#define ERTS_ALC_T_ARG_REG (13140)
#define ERTS_ALC_T_PROC_DICT (13268)
#define ERTS_ALC_T_CALLS_BUF (13396)
#define ERTS_ALC_T_BPD (13540)
#define ERTS_ALC_T_LINEBUF (13668)
#define ERTS_ALC_T_IOQ (13796)
#define ERTS_ALC_T_BITS_BUF (13924)
#define ERTS_ALC_T_DB_NTAB_ENT (14020)
#define ERTS_ALC_T_DDLL_HANDLE (14180)
#define ERTS_ALC_T_RE_HEAP (14308)
#define ERTS_ALC_T_PSD (14420)
#define ERTS_ALC_T_PRTSD (14564)
#define ERTS_ALC_T_MREF_ENT (14692)
#define ERTS_ALC_T_MREF_TAB_BKTS (14820)
#define ERTS_ALC_T_PREF_ENT (14948)
#define ERTS_ALC_T_PREF_TAB_BKTS (15076)
#define ERTS_ALC_T_CRASH_DUMP (15204)
#define ERTS_ALC_T_THR_Q_EL (15332)
#define ERTS_ALC_T_THR_Q (15460)
#define ERTS_ALC_T_ZLIB (15588)
#define ERTS_ALC_T_DRIVER_LOCK (15716)
#define ERTS_ALC_T_ML_DIST (15844)
#define ERTS_ALC_T_ETHR_STD (15972)
#define ERTS_ALC_T_DDLL_PROCESS (16100)
#define ERTS_ALC_T_MONITOR_EXT (16212)
#define ERTS_ALC_T_LINK_EXT (16340)
#define ERTS_ALC_T_DB_HEIR_DATA (16452)
#define ERTS_ALC_T_NFUNC_TRAP_WRAPPER (16596)
#define ERTS_ALC_T_MONITOR_TAG (16724)
#define ERTS_ALC_T_ALIAS (16852)
#define ERTS_ALC_T_MONITOR_SUSPEND (16980)
#define ERTS_ALC_T_PORT_DATA_HEAP (17124)
#define ERTS_ALC_T_ATOMICS (17252)
#define ERTS_ALC_T_COUNTERS (17380)
#define ERTS_ALC_T_FD_ENTRY_BUF (17508)
#define ERTS_ALC_T_SYS_BLOCKING (17636)
#define ERTS_ALC_T_ATOM (17685)
#define ERTS_ALC_T_MODULE (17845)
#define ERTS_ALC_T_FUN_ENTRY (17973)
#define ERTS_ALC_T_ATOM_TXT (18069)
#define ERTS_ALC_T_TIMER_SERVICE (18277)
#define ERTS_ALC_T_ATOM_TABLE (18325)
#define ERTS_ALC_T_MODULE_TABLE (18485)
#define ERTS_ALC_T_TAINT (18613)
#define ERTS_ALC_T_PROC_TABLE (18773)
#define ERTS_ALC_T_PORT_TABLE (18917)
#define ERTS_ALC_T_TIMER_WHEEL (19045)
#define ERTS_ALC_T_ASYNC_DATA (19173)
#define ERTS_ALC_T_DB_TABLES (19269)
#define ERTS_ALC_T_SCHDLR_SLP_INFO (19429)
#define ERTS_ALC_T_RUNQS (19557)
#define ERTS_ALC_T_DDLL_ERRCODES (19685)
#define ERTS_ALC_T_PRE_ALLOC_DATA (19813)
#define ERTS_ALC_T_CPUDATA (19941)
#define ERTS_ALC_T_CPU_GRPS_MAP (20069)
#define ERTS_ALC_T_MISC_AUX_WORK_Q (20197)
#define ERTS_ALC_T_TRACER_NIF (20325)
#define ERTS_ALC_T_MREF_TAB (20453)
#define ERTS_ALC_T_PREF_TAB (20581)
#define ERTS_ALC_T_RLA_BLOCK_CNTRS (20709)
#define ERTS_ALC_T_THR_Q_LL (20837)
#define ERTS_ALC_T_RUNQ_BLNS (20965)
#define ERTS_ALC_T_THR_PRGR_IDATA (21093)
#define ERTS_ALC_T_THR_PRGR_DATA (21221)
#define ERTS_ALC_T_PERSISTENT_TERM (21301)
#define ERTS_ALC_T_ETHR_LL (21477)
#define ERTS_ALC_T_FP_EXCEPTION (21605)
#define ERTS_ALC_T_LL_MPATHS (21733)
#define ERTS_ALC_T_EXPORT_TABLE (21813)
#define ERTS_ALC_T_EXPORT (21941)
#define ERTS_ALC_T_CATCHES (22069)
#define ERTS_ALC_T_DB_MS_PSDO_PROC (22213)
#define ERTS_ALC_T_SCHDLR_DATA (22373)
#define ERTS_ALC_T_DRV_TAB (22501)
#define ERTS_ALC_T_DRV_EV_STATE (22629)
#define ERTS_ALC_T_POLLSET (22757)
#define ERTS_ALC_T_POLL_FDS (22885)
#define ERTS_ALC_T_BLOCK_PTHR_DATA (23013)
#define ERTS_ALC_T_FD_STATUS (23141)
#define ERTS_ALC_T_SELECT_FDS (23269)
#define ERTS_ALC_T_CS_PROG_PATH (23397)
#define ERTS_ALC_T_BEAM_REGISTER (23510)
#define ERTS_ALC_T_HEAP (23638)
#define ERTS_ALC_T_OLD_HEAP (23766)
#define ERTS_ALC_T_HEAP_FRAG (23894)
#define ERTS_ALC_T_MSG (24022)
#define ERTS_ALC_T_DB_TABLE (24135)
#define ERTS_ALC_T_DB_SEG (24263)
#define ERTS_ALC_T_DB_STK (24391)
#define ERTS_ALC_T_DB_TRANS_TAB (24519)
#define ERTS_ALC_T_DB_SEL_LIST (24647)
#define ERTS_ALC_T_DB_DMC_ERROR (24775)
#define ERTS_ALC_T_DB_DMC_ERR_INFO (24903)
#define ERTS_ALC_T_DB_TERM (25031)
#define ERTS_ALC_T_ETS_CTRS (25159)
#define ERTS_ALC_T_PROC (25304)
#define ERTS_ALC_T_RECV_MARK_BLK (25432)
#define ERTS_ALC_T_MSG_REF (25560)
#define ERTS_ALC_T_LL_PTIMER (25688)
#define ERTS_ALC_T_HL_PTIMER (25816)
#define ERTS_ALC_T_BIF_TIMER (25944)
#define ERTS_ALC_T_MREF_NSCHED_ENT (26088)
#define ERTS_ALC_T_PREF_NSCHED_ENT (26216)
#define ERTS_ALC_T_MINDIRECTION (26344)
#define ERTS_ALC_T_SIGQ_BUFFERS (26456)
#define ERTS_ALC_T_THR_Q_EL_SL (26600)
#define ERTS_ALC_T_MONITOR (26712)
#define ERTS_ALC_T_LINK (26840)
#define ERTS_ALC_T_DRV_SEL_D_STATE (26984)
#define ERTS_ALC_T_NIF_SEL_D_STATE (27112)
#define ERTS_ALC_T_LITERAL (27193)
#define ERTS_ALC_T_DRV_BINARY (27306)
#define ERTS_ALC_T_BINARY (27434)
#define ERTS_ALC_T_PORT (27627)
#define ERTS_ALC_T_DRV (27755)
#define ERTS_ALC_T_DRIVER (27883)
#define ERTS_ALC_T_DRV_CMD_DATA (28011)
#define ERTS_ALC_T_DRV_CTRL_DATA (28139)
#define ERTS_ALC_T_DRV_CALL_DATA (28267)
#define ERTS_ALC_T_NIF (28395)
#define ERTS_ALC_T_PORT_DATA_LOCK (28523)
#define ERTS_ALC_T_DRV_THR_OPTS (28651)
#define ERTS_ALC_T_DRV_TID (28779)
#define ERTS_ALC_T_DRV_MTX (28907)
#define ERTS_ALC_T_DRV_CND (29035)
#define ERTS_ALC_T_DRV_RWLCK (29163)
#define ERTS_ALC_T_DRV_TSD (29291)
#define ERTS_ALC_T_MSACC (29419)
#define ERTS_ALC_T_TEST (29548)


/* --- Field sizes, masks, and shifts -------------------------------------- */

#define ERTS_ALC_A_BITS (4)
#define ERTS_ALC_C_BITS (3)
#define ERTS_ALC_N_BITS (8)
#define ERTS_ALC_T_BITS (15)

#define ERTS_ALC_A_MASK (15)
#define ERTS_ALC_C_MASK (7)
#define ERTS_ALC_N_MASK (255)
#define ERTS_ALC_T_MASK (32767)

#define ERTS_ALC_A_SHIFT (0)
#define ERTS_ALC_C_SHIFT (4)
#define ERTS_ALC_N_SHIFT (7)


/* --- Mappings ------------------------------------------------------------ */

/* type -> type number */
#define ERTS_ALC_T2N(T) (((T) >> ERTS_ALC_N_SHIFT) & ERTS_ALC_N_MASK)

/* type -> allocator number */
#define ERTS_ALC_T2A(T) (((T) >> ERTS_ALC_A_SHIFT) & ERTS_ALC_A_MASK)

/* type -> class number */
#define ERTS_ALC_T2C(T) (((T) >> ERTS_ALC_C_SHIFT) & ERTS_ALC_C_MASK)

/* type number -> type */
#define ERTS_ALC_N2T(N) (erts_alc_n2t[(N)])

/* type number -> type description */
#define ERTS_ALC_N2TD(N) (erts_alc_n2td[(N)])

/* type -> type description */
#define ERTS_ALC_T2TD(T) (ERTS_ALC_N2TD(ERTS_ALC_T2N((T))))

/* class number -> class description */
#define ERTS_ALC_C2CD(C) (erts_alc_c2cd[(C)])

/* allocator number -> allocator description */
#define ERTS_ALC_A2AD(A) (erts_alc_a2ad[(A)])

extern const ErtsAlcType_t erts_alc_n2t[];
extern const char *erts_alc_n2td[];
extern const char *erts_alc_c2cd[];
extern const char *erts_alc_a2ad[];

#ifdef ERTS_ALC_INTERNAL__

const ErtsAlcType_t erts_alc_n2t[] = {
  ERTS_ALC_T_INVALID,
  ERTS_ALC_T_UNDEF,
  ERTS_ALC_T_NBIF_TABLE,
  ERTS_ALC_T_INFO_DSBUF,
  ERTS_ALC_T_ENVIRONMENT,
  ERTS_ALC_T_TMP_HEAP,
  ERTS_ALC_T_ROOTSET,
  ERTS_ALC_T_LOADER_TMP,
  ERTS_ALC_T_NC_TMP,
  ERTS_ALC_T_TMP,
  ERTS_ALC_T_DCTRL_BUF,
  ERTS_ALC_T_ESTACK,
  ERTS_ALC_T_DB_TMP,
  ERTS_ALC_T_DB_MC_STK,
  ERTS_ALC_T_DB_MS_CMPL_HEAP,
  ERTS_ALC_T_LOGGER_DSBUF,
  ERTS_ALC_T_TMP_DSBUF,
  ERTS_ALC_T_DDLL_TMP_BUF,
  ERTS_ALC_T_RE_TMP_BUF,
  ERTS_ALC_T_TEMP_TERM,
  ERTS_ALC_T_SYS_READ_BUF,
  ERTS_ALC_T_SYS_WRITE_BUF,
  ERTS_ALC_T_PROC_LIST,
  ERTS_ALC_T_SAVED_ESTACK,
  ERTS_ALC_T_MSGQ_CHNG,
  ERTS_ALC_T_PREPARED_CODE,
  ERTS_ALC_T_TIMER_REQUEST,
  ERTS_ALC_T_BTM_YIELD_STATE,
  ERTS_ALC_T_DB_FIXATION,
  ERTS_ALC_T_DB_FIX_DEL,
  ERTS_ALC_T_DB_MS_RUN_HEAP,
  ERTS_ALC_T_DB_PROC_CLEANUP,
  ERTS_ALC_T_ETS_ALL_REQ,
  ERTS_ALC_T_ETS_I_LST_TRAP,
  ERTS_ALC_T_PORT_TASK,
  ERTS_ALC_T_PT_HNDL_LIST,
  ERTS_ALC_T_MISC_OP_LIST,
  ERTS_ALC_T_PORT_NAMES,
  ERTS_ALC_T_PTAB_LIST_DEL,
  ERTS_ALC_T_PTAB_LIST_CNKI,
  ERTS_ALC_T_PTAB_LIST_PIDS,
  ERTS_ALC_T_RE_SUBJECT,
  ERTS_ALC_T_RE_STACK,
  ERTS_ALC_T_UNICODE_BUFFER,
  ERTS_ALC_T_BINARY_BUFFER,
  ERTS_ALC_T_TMP_CPU_IDS,
  ERTS_ALC_T_EXT_TERM_DATA,
  ERTS_ALC_T_CODE_IX_LOCK_Q,
  ERTS_ALC_T_BUSY_CALLER_TAB,
  ERTS_ALC_T_BUSY_CALLER,
  ERTS_ALC_T_PROC_SYS_TSK,
  ERTS_ALC_T_PROC_SYS_TSK_QS,
  ERTS_ALC_T_NEW_TIME_OFFSET,
  ERTS_ALC_T_IOB_REQ,
  ERTS_ALC_T_TRACE_MSG_QUEUE,
  ERTS_ALC_T_DIRTY_SL,
  ERTS_ALC_T_BINARY_FIND,
  ERTS_ALC_T_DIST_TRANSCODE,
  ERTS_ALC_T_MISC_AUX_WORK,
  ERTS_ALC_T_THR_Q_SL,
  ERTS_ALC_T_ASYNC,
  ERTS_ALC_T_XPORTS_LIST,
  ERTS_ALC_T_T_THR_PRGR_DATA,
  ERTS_ALC_T_RELEASE_LAREA,
  ERTS_ALC_T_SIG_DATA,
  ERTS_ALC_T_SIG_YIELD_DATA,
  ERTS_ALC_T_DIST_DEMONITOR,
  ERTS_ALC_T_CML_CLEANUP,
  ERTS_ALC_T_ML_YIELD_STATE,
  ERTS_ALC_T_PF3_ARGS,
  ERTS_ALC_T_SETUP_CONN_ARG,
  ERTS_ALC_T_LIST_TRAP,
  ERTS_ALC_T_CONT_EXIT_TRAP,
  ERTS_ALC_T_SEQ_YIELD_STATE,
  ERTS_ALC_T_PHASH2_TRAP,
  ERTS_ALC_T_MAP_TRAP,
  ERTS_ALC_T_PERSISTENT_LOCK_Q,
  ERTS_ALC_T_PERSISTENT_TERM_TMP,
  ERTS_ALC_T_T2B_VEC,
  ERTS_ALC_T_ETHR_SL,
  ERTS_ALC_T_SYS_MSG_Q,
  ERTS_ALC_T_SL_MPATHS,
  ERTS_ALC_T_T2B_DETERMINISTIC,
  ERTS_ALC_T_DEBUG,
  ERTS_ALC_T_LITERAL_REF,
  ERTS_ALC_T_PURGE_DATA,
  ERTS_ALC_T_AINFO_REQ,
  ERTS_ALC_T_SCHED_WTIME_REQ,
  ERTS_ALC_T_GC_INFO_REQ,
  ERTS_ALC_T_SYS_CHECK_REQ,
  ERTS_ALC_T_SHORT_LIVED_TERM,
  ERTS_ALC_T_POLLSET_UPDREQ,
  ERTS_ALC_T_REG_PROC,
  ERTS_ALC_T_REG_TABLE,
  ERTS_ALC_T_FUN_TABLE,
  ERTS_ALC_T_DIST_TABLE,
  ERTS_ALC_T_NODE_TABLE,
  ERTS_ALC_T_MODULE_REFS,
  ERTS_ALC_T_NC_STD,
  ERTS_ALC_T_DCACHE,
  ERTS_ALC_T_DIST_ENTRY,
  ERTS_ALC_T_NODE_ENTRY,
  ERTS_ALC_T_ARG_REG,
  ERTS_ALC_T_PROC_DICT,
  ERTS_ALC_T_CALLS_BUF,
  ERTS_ALC_T_BPD,
  ERTS_ALC_T_LINEBUF,
  ERTS_ALC_T_IOQ,
  ERTS_ALC_T_BITS_BUF,
  ERTS_ALC_T_DB_NTAB_ENT,
  ERTS_ALC_T_DDLL_HANDLE,
  ERTS_ALC_T_RE_HEAP,
  ERTS_ALC_T_PSD,
  ERTS_ALC_T_PRTSD,
  ERTS_ALC_T_MREF_ENT,
  ERTS_ALC_T_MREF_TAB_BKTS,
  ERTS_ALC_T_PREF_ENT,
  ERTS_ALC_T_PREF_TAB_BKTS,
  ERTS_ALC_T_CRASH_DUMP,
  ERTS_ALC_T_THR_Q_EL,
  ERTS_ALC_T_THR_Q,
  ERTS_ALC_T_ZLIB,
  ERTS_ALC_T_DRIVER_LOCK,
  ERTS_ALC_T_ML_DIST,
  ERTS_ALC_T_ETHR_STD,
  ERTS_ALC_T_DDLL_PROCESS,
  ERTS_ALC_T_MONITOR_EXT,
  ERTS_ALC_T_LINK_EXT,
  ERTS_ALC_T_DB_HEIR_DATA,
  ERTS_ALC_T_NFUNC_TRAP_WRAPPER,
  ERTS_ALC_T_MONITOR_TAG,
  ERTS_ALC_T_ALIAS,
  ERTS_ALC_T_MONITOR_SUSPEND,
  ERTS_ALC_T_PORT_DATA_HEAP,
  ERTS_ALC_T_ATOMICS,
  ERTS_ALC_T_COUNTERS,
  ERTS_ALC_T_FD_ENTRY_BUF,
  ERTS_ALC_T_SYS_BLOCKING,
  ERTS_ALC_T_ATOM,
  ERTS_ALC_T_MODULE,
  ERTS_ALC_T_FUN_ENTRY,
  ERTS_ALC_T_ATOM_TXT,
  ERTS_ALC_T_TIMER_SERVICE,
  ERTS_ALC_T_ATOM_TABLE,
  ERTS_ALC_T_MODULE_TABLE,
  ERTS_ALC_T_TAINT,
  ERTS_ALC_T_PROC_TABLE,
  ERTS_ALC_T_PORT_TABLE,
  ERTS_ALC_T_TIMER_WHEEL,
  ERTS_ALC_T_ASYNC_DATA,
  ERTS_ALC_T_DB_TABLES,
  ERTS_ALC_T_SCHDLR_SLP_INFO,
  ERTS_ALC_T_RUNQS,
  ERTS_ALC_T_DDLL_ERRCODES,
  ERTS_ALC_T_PRE_ALLOC_DATA,
  ERTS_ALC_T_CPUDATA,
  ERTS_ALC_T_CPU_GRPS_MAP,
  ERTS_ALC_T_MISC_AUX_WORK_Q,
  ERTS_ALC_T_TRACER_NIF,
  ERTS_ALC_T_MREF_TAB,
  ERTS_ALC_T_PREF_TAB,
  ERTS_ALC_T_RLA_BLOCK_CNTRS,
  ERTS_ALC_T_THR_Q_LL,
  ERTS_ALC_T_RUNQ_BLNS,
  ERTS_ALC_T_THR_PRGR_IDATA,
  ERTS_ALC_T_THR_PRGR_DATA,
  ERTS_ALC_T_PERSISTENT_TERM,
  ERTS_ALC_T_ETHR_LL,
  ERTS_ALC_T_FP_EXCEPTION,
  ERTS_ALC_T_LL_MPATHS,
  ERTS_ALC_T_EXPORT_TABLE,
  ERTS_ALC_T_EXPORT,
  ERTS_ALC_T_CATCHES,
  ERTS_ALC_T_DB_MS_PSDO_PROC,
  ERTS_ALC_T_SCHDLR_DATA,
  ERTS_ALC_T_DRV_TAB,
  ERTS_ALC_T_DRV_EV_STATE,
  ERTS_ALC_T_POLLSET,
  ERTS_ALC_T_POLL_FDS,
  ERTS_ALC_T_BLOCK_PTHR_DATA,
  ERTS_ALC_T_FD_STATUS,
  ERTS_ALC_T_SELECT_FDS,
  ERTS_ALC_T_CS_PROG_PATH,
  ERTS_ALC_T_BEAM_REGISTER,
  ERTS_ALC_T_HEAP,
  ERTS_ALC_T_OLD_HEAP,
  ERTS_ALC_T_HEAP_FRAG,
  ERTS_ALC_T_MSG,
  ERTS_ALC_T_DB_TABLE,
  ERTS_ALC_T_DB_SEG,
  ERTS_ALC_T_DB_STK,
  ERTS_ALC_T_DB_TRANS_TAB,
  ERTS_ALC_T_DB_SEL_LIST,
  ERTS_ALC_T_DB_DMC_ERROR,
  ERTS_ALC_T_DB_DMC_ERR_INFO,
  ERTS_ALC_T_DB_TERM,
  ERTS_ALC_T_ETS_CTRS,
  ERTS_ALC_T_PROC,
  ERTS_ALC_T_RECV_MARK_BLK,
  ERTS_ALC_T_MSG_REF,
  ERTS_ALC_T_LL_PTIMER,
  ERTS_ALC_T_HL_PTIMER,
  ERTS_ALC_T_BIF_TIMER,
  ERTS_ALC_T_MREF_NSCHED_ENT,
  ERTS_ALC_T_PREF_NSCHED_ENT,
  ERTS_ALC_T_MINDIRECTION,
  ERTS_ALC_T_SIGQ_BUFFERS,
  ERTS_ALC_T_THR_Q_EL_SL,
  ERTS_ALC_T_MONITOR,
  ERTS_ALC_T_LINK,
  ERTS_ALC_T_DRV_SEL_D_STATE,
  ERTS_ALC_T_NIF_SEL_D_STATE,
  ERTS_ALC_T_LITERAL,
  ERTS_ALC_T_DRV_BINARY,
  ERTS_ALC_T_BINARY,
  ERTS_ALC_T_PORT,
  ERTS_ALC_T_DRV,
  ERTS_ALC_T_DRIVER,
  ERTS_ALC_T_DRV_CMD_DATA,
  ERTS_ALC_T_DRV_CTRL_DATA,
  ERTS_ALC_T_DRV_CALL_DATA,
  ERTS_ALC_T_NIF,
  ERTS_ALC_T_PORT_DATA_LOCK,
  ERTS_ALC_T_DRV_THR_OPTS,
  ERTS_ALC_T_DRV_TID,
  ERTS_ALC_T_DRV_MTX,
  ERTS_ALC_T_DRV_CND,
  ERTS_ALC_T_DRV_RWLCK,
  ERTS_ALC_T_DRV_TSD,
  ERTS_ALC_T_MSACC,
  ERTS_ALC_T_TEST,
  ERTS_ALC_T_INVALID
};

const char *erts_alc_n2td[] = {
  "invalid_type",
  "undefined",
  "nbif_tab",
  "info_dsbuf",
  "environment",
  "tmp_heap",
  "root_set",
  "loader_tmp",
  "nc_tmp",
  "tmp",
  "dctrl_buf",
  "estack",
  "db_tmp",
  "db_mc_stack",
  "db_match_spec_cmpl_heap",
  "logger_dsbuf",
  "tmp_dsbuf",
  "ddll_tmp_buf",
  "re_tmp_buf",
  "temp_term",
  "sys_read_buf",
  "sys_write_buf",
  "proc_list",
  "saved_estack",
  "messages_queue_change",
  "prepared_code",
  "timer_request",
  "btm_yield_state",
  "db_fixation",
  "fixed_del",
  "db_match_spec_run_heap",
  "db_proc_cleanup_state",
  "ets_all_request",
  "ets_insert_list_bif_trap_state",
  "port_task",
  "port_task_handle_list",
  "misc_op_list",
  "port_names",
  "ptab_list_deleted_el",
  "ptab_list_chunk_info",
  "ptab_list_pids",
  "re_subject",
  "re_stack",
  "unicode_buffer",
  "binary_buffer",
  "tmp_cpu_ids",
  "external_term_data",
  "code_ix_lock_q",
  "busy_caller_table",
  "busy_caller",
  "proc_sys_task",
  "proc_sys_task_queues",
  "new_time_offset",
  "io_bytes_request",
  "trace_message_queue",
  "dirty_short_lived",
  "binary_find",
  "dist_transcode_context",
  "misc_aux_work",
  "short_lived_thr_queue",
  "async",
  "extra_port_list",
  "temp_thr_prgr_data",
  "release_literal_area",
  "signal_data",
  "signal_yield_data",
  "dist_demonitor",
  "connection_ml_cleanup",
  "monitor_link_yield_state",
  "process_flag_3_arguments",
  "setup_connection_argument",
  "list_bif_trap_state",
  "continue_exit_trap_state",
  "dist_seq_yield_state",
  "phash2_trap_state",
  "map_bif_trap_state",
  "persistent_lock_q",
  "persistent_term_tmp_table",
  "term_to_binary_vector",
  "ethread_short_lived",
  "system_messages_queue",
  "sl_migration_paths",
  "term_to_binary_deterministic",
  "debugging",
  "literal_area_ref",
  "purge_data",
  "alloc_info_request",
  "sched_wall_time_request",
  "gc_info_request",
  "system_check_request",
  "short_lived_term",
  "pollset_update_req",
  "reg_proc",
  "reg_tab",
  "fun_tab",
  "dist_tab",
  "node_tab",
  "module_refs",
  "nc_std",
  "dcache",
  "dist_entry",
  "node_entry",
  "arg_reg",
  "proc_dict",
  "calls_buf",
  "bpd",
  "line_buf",
  "io_queue",
  "bits_buf",
  "db_named_table_entry",
  "ddll_handle",
  "re_heap",
  "process_specific_data",
  "port_specific_data",
  "magic_ref_entry",
  "magic_ref_table_buckets",
  "pid_ref_entry",
  "pid_ref_table_buckets",
  "crash_dump",
  "thr_q_element",
  "thr_queue",
  "zlib",
  "driver_lock",
  "monitor_link_dist",
  "ethread_standard",
  "ddll_processes",
  "monitor_extended",
  "link_extended",
  "db_heir_data",
  "nfunc_trap_wrapper",
  "monitor_tag",
  "alias",
  "monitor_suspend",
  "port_data_heap",
  "erl_bif_atomics",
  "erl_bif_counters",
  "fd_entry_buf",
  "sys_blocking",
  "atom_entry",
  "module_entry",
  "fun_entry",
  "atom_text",
  "timer_service",
  "atom_tab",
  "module_tab",
  "taint_list",
  "proc_tab",
  "port_tab",
  "timer_wheel",
  "internal_async_data",
  "db_tabs",
  "scheduler_sleep_info",
  "run_queues",
  "ddll_errcodes",
  "pre_alloc_data",
  "cpu_data",
  "cpu_groups_map",
  "misc_aux_work_q",
  "tracer_nif",
  "magic_ref_table",
  "pid_ref_table",
  "release_literal_area_block_counters",
  "long_lived_thr_queue",
  "run_queue_balancing",
  "thr_prgr_internal_data",
  "thr_prgr_data",
  "persisten_term",
  "ethread_long_lived",
  "fp_exception",
  "ll_migration_paths",
  "export_tab",
  "export_entry",
  "catches",
  "db_match_pseudo_proc",
  "scheduler_data",
  "drv_tab",
  "driver_event_state",
  "pollset",
  "poll_fds",
  "block_poll_thread_data",
  "fd_status",
  "select_fds",
  "cs_prog_path",
  "beam_register",
  "heap",
  "old_heap",
  "heap_frag",
  "message",
  "db_tab",
  "db_segment",
  "db_stack",
  "db_trans_tab",
  "db_select_list",
  "db_dmc_error",
  "db_dmc_error_info",
  "db_term",
  "ets_decentralized_ctrs",
  "proc",
  "receive_marker_block",
  "msg_ref",
  "ll_ptimer",
  "hl_ptimer",
  "bif_timer",
  "nsched_magic_ref_entry",
  "nsched_pid_ref_entry",
  "magic_indirection",
  "process_signal_queue_buffers",
  "sl_thr_q_element",
  "monitor",
  "link",
  "driver_select_data_state",
  "enif_select_data_state",
  "literal",
  "drv_binary",
  "binary",
  "port",
  "drv_internal",
  "driver",
  "driver_command_data",
  "driver_control_data",
  "driver_call_data",
  "nif_internal",
  "port_data_lock",
  "driver_thread_opts",
  "driver_tid",
  "driver_mutex",
  "driver_cond",
  "driver_rwlock",
  "driver_tsd",
  "microstate_accounting",
  "testing",
  NULL
};

const char *erts_alc_c2cd[] = {
  "invalid_class",
  "atom_data",
  "binary_data",
  "code_data",
  "ets_data",
  "process_data",
  "system_data",
  NULL
};

const char *erts_alc_a2ad[] = {
  "invalid_allocator",
  "sys_alloc",
  "temp_alloc",
  "sl_alloc",
  "std_alloc",
  "ll_alloc",
  "eheap_alloc",
  "ets_alloc",
  "fix_alloc",
  "literal_alloc",
  "binary_alloc",
  "driver_alloc",
  "test_alloc",
  NULL
};

#endif /* #ifdef ERTS_ALC_INTERNAL__ */


/* ------------------------------------------------------------------------- */
#endif /* #ifndef ERL_ALLOC_TYPES_H__ */