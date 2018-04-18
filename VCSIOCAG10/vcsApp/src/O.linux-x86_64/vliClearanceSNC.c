/* C code for program vliClearanceSNC, generated by snc from ../vliClearanceSNC.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../vliClearanceSNC.stt"

/*******************************************************************/
#include "vcs_var_mes.h" // define this here so C functions are seen
/*******************************************************************/
#define	VCOK       	0
#define TOUT		5
#define FAIL		-1
#define VLIPNK      138
#define	G4ON		82
#define	G4S1ON		83
#define	G4S2ON		84
#define	B33OFF      100
#define	B32ON       97
#define	DA004ON     96
#define DA004S1OFF	98 
#define DA004S2OFF	99


/* Variable declarations */
# line 21 "../vliClearanceSNC.stt"
static	short VLI_INIT;
# line 22 "../vliClearanceSNC.stt"
static	short VLI_VC;
# line 23 "../vliClearanceSNC.stt"
static	short VLI_W32_STS;
# line 24 "../vliClearanceSNC.stt"
static	short VLI_W33_STS;
# line 25 "../vliClearanceSNC.stt"
static	short VLI_FAIL_COND;
# line 26 "../vliClearanceSNC.stt"
static	string VLI_CLR_STATS;
# line 27 "../vliClearanceSNC.stt"
static	string VLI_INTLCK_STATS;
# line 29 "../vliClearanceSNC.stt"
static	short vliUpdate;
# line 30 "../vliClearanceSNC.stt"
static	short VLI_OLD_FAIL_COND;


/* Function declarations */
# line 172 "../vliClearanceSNC.stt"
static void initVault(SS_ID seqg_env);
# line 182 "../vliClearanceSNC.stt"
static void resetStatus(SS_ID seqg_env);
# line 190 "../vliClearanceSNC.stt"
static void VLI_update_failed(SS_ID seqg_env, short report);
# line 199 "../vliClearanceSNC.stt"
static void VLI_update_report(SS_ID seqg_env, short intlck);
# line 204 "../vliClearanceSNC.stt"
static void VLI_status(SS_ID seqg_env);
# line 212 "../vliClearanceSNC.stt"
static void VLI_clear_underway(SS_ID seqg_env);

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "init" in state set "VLI_clearance_status" ******/

/* Event function for state "init" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 49 "../vliClearanceSNC.stt"
	if (seq_delay(seqg_env, 9.5))
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 50 "../vliClearanceSNC.stt"
			initVault(seqg_env);
# line 51 "../vliClearanceSNC.stt"
			printf("%sVERTICAL BEAMLINE VAULT INITIALISATION COMPLETED%s\n", OK, DEF);
		}
		return;
	}
}

/****** Code for state "vault_cleared" in state set "VLI_clearance_status" ******/

/* Entry function for state "vault_cleared" in state set "VLI_clearance_status" */
static void seqg_entry_VLI_clearance_status_0_vault_cleared(SS_ID seqg_env)
{
# line 59 "../vliClearanceSNC.stt"
	printf("%sVERTICAL BEAMLINE VAULT IN CLEARED STATE%s\n", CLR, DEF);
}

/* Event function for state "vault_cleared" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_vault_cleared(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 61 "../vliClearanceSNC.stt"
	if (VLI_VC != VCOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vault_cleared" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_vault_cleared(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "recover_faillure" in state set "VLI_clearance_status" ******/

/* Event function for state "recover_faillure" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_recover_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 68 "../vliClearanceSNC.stt"
	if (!VLI_FAIL_COND)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 75 "../vliClearanceSNC.stt"
	if (VLI_FAIL_COND != VLI_OLD_FAIL_COND)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_faillure" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_recover_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 69 "../vliClearanceSNC.stt"
			if (!vliUpdate)
			{
# line 70 "../vliClearanceSNC.stt"
				printf("%sRECOVERING FROM FAILLURE - ENTERING W32 STATE: %d%s\n", OK, VLI_W32_STS, DEF);
# line 71 "../vliClearanceSNC.stt"
				vliUpdate = TRUE;
			}
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "watchman_32_pressed" in state set "VLI_clearance_status" ******/

/* Event function for state "watchman_32_pressed" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_watchman_32_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 82 "../vliClearanceSNC.stt"
	if (VLI_FAIL_COND != VCOK)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 86 "../vliClearanceSNC.stt"
	if (VLI_W32_STS == B32ON)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_32_pressed" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_watchman_32_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 83 "../vliClearanceSNC.stt"
			VLI_OLD_FAIL_COND = VLI_FAIL_COND;
		}
		return;
	case 1:
		{
# line 87 "../vliClearanceSNC.stt"
			VLI_clear_underway(seqg_env);
# line 88 "../vliClearanceSNC.stt"
			VLI_update_report(seqg_env, B32ON);
		}
		return;
	}
}

/****** Code for state "watchman_32_released" in state set "VLI_clearance_status" ******/

/* Event function for state "watchman_32_released" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_watchman_32_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 94 "../vliClearanceSNC.stt"
	if (VLI_W32_STS == FAIL)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 98 "../vliClearanceSNC.stt"
	if (VLI_W32_STS != B32ON)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_32_released" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_watchman_32_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "door_a004_closed" in state set "VLI_clearance_status" ******/

/* Event function for state "door_a004_closed" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_door_a004_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 104 "../vliClearanceSNC.stt"
	if (VLI_FAIL_COND != VCOK)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 108 "../vliClearanceSNC.stt"
	if (VLI_W33_STS == DA004S1OFF)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 112 "../vliClearanceSNC.stt"
	if (VLI_W33_STS == DA004S2OFF)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 2;
		return TRUE;
	}
	if (TRUE)
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 3;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "door_a004_closed" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_door_a004_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 109 "../vliClearanceSNC.stt"
			VLI_update_report(seqg_env, DA004S1OFF);
		}
		return;
	case 2:
		{
# line 113 "../vliClearanceSNC.stt"
			VLI_update_report(seqg_env, DA004S2OFF);
		}
		return;
	case 3:
		{
# line 117 "../vliClearanceSNC.stt"
			VLI_update_report(seqg_env, B33OFF);
		}
		return;
	}
}

/****** Code for state "watchman_33_pressed" in state set "VLI_clearance_status" ******/

/* Event function for state "watchman_33_pressed" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_watchman_33_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 124 "../vliClearanceSNC.stt"
	if (VLI_W33_STS == FAIL)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 129 "../vliClearanceSNC.stt"
	if (!VLI_W33_STS)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_33_pressed" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_watchman_33_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 131 "../vliClearanceSNC.stt"
			VLI_status(seqg_env);
		}
		return;
	}
}

/****** Code for state "clearance_faillures" in state set "VLI_clearance_status" ******/

/* Entry function for state "clearance_faillures" in state set "VLI_clearance_status" */
static void seqg_entry_VLI_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 140 "../vliClearanceSNC.stt"
	printf("VLI CLEARANCE FAILURE CONDITION: ");
# line 141 "../vliClearanceSNC.stt"
	vliUpdate = FALSE;
}

/* Exit function for state "clearance_faillures" in state set "VLI_clearance_status" */
static void seqg_exit_VLI_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 149 "../vliClearanceSNC.stt"
	VLI_OLD_FAIL_COND = VLI_FAIL_COND;
}

/* Event function for state "clearance_faillures" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_clearance_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_faillures" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_clearance_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 145 "../vliClearanceSNC.stt"
			VLI_update_failed(seqg_env, VLI_FAIL_COND);
		}
		return;
	}
}

/****** Code for state "vc_faillures" in state set "VLI_clearance_status" ******/

/* Entry function for state "vc_faillures" in state set "VLI_clearance_status" */
static void seqg_entry_VLI_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 158 "../vliClearanceSNC.stt"
	printf("VLI CLEAR FAILURE CONDITION: ");
# line 159 "../vliClearanceSNC.stt"
	vliUpdate = FALSE;
}

/* Exit function for state "vc_faillures" in state set "VLI_clearance_status" */
static void seqg_exit_VLI_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 167 "../vliClearanceSNC.stt"
	VLI_OLD_FAIL_COND = VLI_FAIL_COND;
}

/* Event function for state "vc_faillures" in state set "VLI_clearance_status" */
static seqBool seqg_event_VLI_clearance_status_0_vc_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vc_faillures" in state set "VLI_clearance_status" */
static void seqg_action_VLI_clearance_status_0_vc_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 163 "../vliClearanceSNC.stt"
			VLI_update_failed(seqg_env, VLI_VC);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{SYS}:VLI-CLR-STATS", (size_t)&VLI_CLR_STATS, "VLI_CLR_STATS", P_STRING, 1, 1, 0, 0, 0, 0},
	{"{SYS}:VLI-INTLCK-STATS", (size_t)&VLI_INTLCK_STATS, "VLI_INTLCK_STATS", P_STRING, 1, 2, 0, 0, 0, 0},
	{"{SYS}:VLI-VC", (size_t)&VLI_VC, "VLI_VC", P_SHORT, 1, 3, 0, 1, 0, 0},
	{"{SYS}:VLI-INIT", (size_t)&VLI_INIT, "VLI_INIT", P_SHORT, 1, 4, 0, 0, 0, 0},
	{"{SYS}:VLI-W32-STS", (size_t)&VLI_W32_STS, "VLI_W32_STS", P_SHORT, 1, 5, 0, 1, 0, 0},
	{"{SYS}:VLI-W33-STS", (size_t)&VLI_W33_STS, "VLI_W33_STS", P_SHORT, 1, 6, 0, 1, 0, 0},
	{"{SYS}:VLI-FAIL-COND", (size_t)&VLI_FAIL_COND, "VLI_FAIL_COND", P_SHORT, 1, 7, 0, 1, 0, 0},
};

/* Event masks for state set "VLI_clearance_status" */
static const seqMask seqg_mask_VLI_clearance_status_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_VLI_clearance_status_0_vault_cleared[] = {
	0x00000008,
};
static const seqMask seqg_mask_VLI_clearance_status_0_recover_faillure[] = {
	0x00000080,
};
static const seqMask seqg_mask_VLI_clearance_status_0_watchman_32_pressed[] = {
	0x000000a0,
};
static const seqMask seqg_mask_VLI_clearance_status_0_watchman_32_released[] = {
	0x00000020,
};
static const seqMask seqg_mask_VLI_clearance_status_0_door_a004_closed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_VLI_clearance_status_0_watchman_33_pressed[] = {
	0x00000040,
};
static const seqMask seqg_mask_VLI_clearance_status_0_clearance_faillures[] = {
	0x00000000,
};
static const seqMask seqg_mask_VLI_clearance_status_0_vc_faillures[] = {
	0x00000000,
};

/* State table for state set "VLI_clearance_status" */
static seqState seqg_states_VLI_clearance_status[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_VLI_clearance_status_0_init,
	/* event function */    seqg_event_VLI_clearance_status_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "vault_cleared",
	/* action function */   seqg_action_VLI_clearance_status_0_vault_cleared,
	/* event function */    seqg_event_VLI_clearance_status_0_vault_cleared,
	/* entry function */    seqg_entry_VLI_clearance_status_0_vault_cleared,
	/* exit function */     0,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_vault_cleared,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "recover_faillure",
	/* action function */   seqg_action_VLI_clearance_status_0_recover_faillure,
	/* event function */    seqg_event_VLI_clearance_status_0_recover_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_recover_faillure,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_32_pressed",
	/* action function */   seqg_action_VLI_clearance_status_0_watchman_32_pressed,
	/* event function */    seqg_event_VLI_clearance_status_0_watchman_32_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_watchman_32_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_32_released",
	/* action function */   seqg_action_VLI_clearance_status_0_watchman_32_released,
	/* event function */    seqg_event_VLI_clearance_status_0_watchman_32_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_watchman_32_released,
	/* state options */     (0)
	},
	{
	/* state name */        "door_a004_closed",
	/* action function */   seqg_action_VLI_clearance_status_0_door_a004_closed,
	/* event function */    seqg_event_VLI_clearance_status_0_door_a004_closed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_door_a004_closed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_33_pressed",
	/* action function */   seqg_action_VLI_clearance_status_0_watchman_33_pressed,
	/* event function */    seqg_event_VLI_clearance_status_0_watchman_33_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_watchman_33_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "clearance_faillures",
	/* action function */   seqg_action_VLI_clearance_status_0_clearance_faillures,
	/* event function */    seqg_event_VLI_clearance_status_0_clearance_faillures,
	/* entry function */    seqg_entry_VLI_clearance_status_0_clearance_faillures,
	/* exit function */     seqg_exit_VLI_clearance_status_0_clearance_faillures,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_clearance_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "vc_faillures",
	/* action function */   seqg_action_VLI_clearance_status_0_vc_faillures,
	/* event function */    seqg_event_VLI_clearance_status_0_vc_faillures,
	/* entry function */    seqg_entry_VLI_clearance_status_0_vc_faillures,
	/* exit function */     seqg_exit_VLI_clearance_status_0_vc_faillures,
	/* event mask array */  seqg_mask_VLI_clearance_status_0_vc_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "VLI_clearance_status",
	/* states */            seqg_states_VLI_clearance_status,
	/* number of states */  9
	},
};

/* Program table (global) */
seqProgram vliClearanceSNC = {
	/* magic number */      2002001,
	/* program name */      "vliClearanceSNC",
	/* channels */          seqg_chans,
	/* num. channels */     7,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 172 "../vliClearanceSNC.stt"
static void initVault(SS_ID seqg_env)
{
# line 173 "../vliClearanceSNC.stt"
	VLI_INIT = TRUE;
# line 174 "../vliClearanceSNC.stt"
	VLI_OLD_FAIL_COND = VLI_FAIL_COND;
# line 175 "../vliClearanceSNC.stt"
	not_cleared(VLI_CLR_STATS);
# line 176 "../vliClearanceSNC.stt"
	report_error(VLI_INTLCK_STATS, 54);
# line 177 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 3/*VLI_INIT*/, SYNC, DEFAULT_TIMEOUT);
# line 178 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*VLI_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 179 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*VLI_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 182 "../vliClearanceSNC.stt"
static void resetStatus(SS_ID seqg_env)
{
# line 184 "../vliClearanceSNC.stt"
	not_cleared(VLI_CLR_STATS);
# line 185 "../vliClearanceSNC.stt"
	report_error(VLI_INTLCK_STATS, 54);
# line 186 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*VLI_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 187 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*VLI_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 190 "../vliClearanceSNC.stt"
static void VLI_update_failed(SS_ID seqg_env, short report)
{
# line 192 "../vliClearanceSNC.stt"
	clear_failed(VLI_CLR_STATS);
# line 193 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*VLI_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 194 "../vliClearanceSNC.stt"
	report_error(VLI_INTLCK_STATS, report);
# line 195 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*VLI_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 196 "../vliClearanceSNC.stt"
	printf("%s%s%s\n", ERROR, VLI_INTLCK_STATS, DEF);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 199 "../vliClearanceSNC.stt"
static void VLI_update_report(SS_ID seqg_env, short intlck)
{
# line 200 "../vliClearanceSNC.stt"
	report_error(VLI_INTLCK_STATS, intlck);
# line 201 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*VLI_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 204 "../vliClearanceSNC.stt"
static void VLI_status(SS_ID seqg_env)
{
# line 206 "../vliClearanceSNC.stt"
	cleared(VLI_CLR_STATS);
# line 207 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*VLI_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 208 "../vliClearanceSNC.stt"
	report_error(VLI_INTLCK_STATS, 54);
# line 209 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*VLI_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 212 "../vliClearanceSNC.stt"
static void VLI_clear_underway(SS_ID seqg_env)
{
# line 214 "../vliClearanceSNC.stt"
	clear_underway(VLI_CLR_STATS);
# line 215 "../vliClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*VLI_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

/* Register sequencer commands and program */
#include "epicsExport.h"
static void vliClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&vliClearanceSNC);
}
epicsExportRegistrar(vliClearanceSNCRegistrar);
