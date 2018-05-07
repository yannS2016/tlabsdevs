/* C code for program spc1basClearanceSNC, generated by snc from ../spc1basClearanceSNC.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../spc1basClearanceSNC.stt"

/*******************************************************************/
#include "vcs_var_mes.h" // define this here so C functions are seen
/*******************************************************************/
#define FAIL		-1 	
#define	VCOK       	0
#define TOUT		5
#define SPC1LPNK	20
#define RA2ON		148
#define B42ON		180
#define B43OFF		183
#define DA001ON		174
#define DA005AON	175
#define DA005ON		176
#define DA005OFF	182
#define A005ON		186


/* Variable declarations */
# line 21 "../spc1basClearanceSNC.stt"
static	short SPC1L_VC;
# line 22 "../spc1basClearanceSNC.stt"
static	short SPC1_W42_STS;
# line 23 "../spc1basClearanceSNC.stt"
static	short SPC1_W43_STS;
# line 24 "../spc1basClearanceSNC.stt"
static	short SPC1L_FAIL_COND;
# line 25 "../spc1basClearanceSNC.stt"
static	short SPC1L_OLD_FAIL_COND;
# line 26 "../spc1basClearanceSNC.stt"
static	string SPC1L_CLR_STATS;
# line 27 "../spc1basClearanceSNC.stt"
static	string SPC1L_INTLCK_STATS;
# line 29 "../spc1basClearanceSNC.stt"
static	short spc1LUpdate;
# line 30 "../spc1basClearanceSNC.stt"
static	short SPC1L_INIT;


/* Function declarations */
# line 164 "../spc1basClearanceSNC.stt"
static void initVault(SS_ID seqg_env);
# line 173 "../spc1basClearanceSNC.stt"
static void SPC1L_update_failed(SS_ID seqg_env, short report);
# line 182 "../spc1basClearanceSNC.stt"
static void SPC1L_update_report(SS_ID seqg_env, short intlck);
# line 187 "../spc1basClearanceSNC.stt"
static void SPC1L_status(SS_ID seqg_env);
# line 195 "../spc1basClearanceSNC.stt"
static void SPC1L_clear_underway(SS_ID seqg_env);

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 29 "../spc1basClearanceSNC.stt"
	static short seqg_initvar_spc1LUpdate = FALSE;
	memcpy(&spc1LUpdate, &seqg_initvar_spc1LUpdate, sizeof(seqg_initvar_spc1LUpdate));
	}
}

/****** Code for state "init" in state set "SPC1L_clearance_status" ******/

/* Event function for state "init" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 47 "../spc1basClearanceSNC.stt"
	if (seq_delay(seqg_env, 0.5))
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 48 "../spc1basClearanceSNC.stt"
			initVault(seqg_env);
# line 49 "../spc1basClearanceSNC.stt"
			printf("\n%sSPC1 BASEMENT VAULT INITIALISATION COMPLETED%s\n", OK, DEF);
		}
		return;
	}
}

/****** Code for state "vault_cleared" in state set "SPC1L_clearance_status" ******/

/* Entry function for state "vault_cleared" in state set "SPC1L_clearance_status" */
static void seqg_entry_SPC1L_clearance_status_0_vault_cleared(SS_ID seqg_env)
{
# line 57 "../spc1basClearanceSNC.stt"
	printf("%sSPC1 BASEMENT VAULT IN CLEARED STATE%s\n", CLR, DEF);
}

/* Event function for state "vault_cleared" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_vault_cleared(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 59 "../spc1basClearanceSNC.stt"
	if (SPC1L_VC != VCOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vault_cleared" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_vault_cleared(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "recover_faillure" in state set "SPC1L_clearance_status" ******/

/* Event function for state "recover_faillure" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_recover_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 66 "../spc1basClearanceSNC.stt"
	if (!SPC1L_FAIL_COND)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 73 "../spc1basClearanceSNC.stt"
	if (SPC1L_FAIL_COND != SPC1L_OLD_FAIL_COND)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_faillure" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_recover_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 67 "../spc1basClearanceSNC.stt"
			if (!spc1LUpdate)
			{
# line 68 "../spc1basClearanceSNC.stt"
				printf("%sRECOVERING FROM FAILLURE - ENTERING W42 STATE%s\n", OK, DEF);
# line 69 "../spc1basClearanceSNC.stt"
				spc1LUpdate = TRUE;
			}
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "watchman_42_pressed" in state set "SPC1L_clearance_status" ******/

/* Event function for state "watchman_42_pressed" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_watchman_42_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 81 "../spc1basClearanceSNC.stt"
	if (SPC1_W42_STS == FAIL)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 85 "../spc1basClearanceSNC.stt"
	if (SPC1_W42_STS == B42ON)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_42_pressed" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_watchman_42_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 82 "../spc1basClearanceSNC.stt"
			SPC1L_OLD_FAIL_COND = SPC1L_FAIL_COND;
		}
		return;
	case 1:
		{
# line 86 "../spc1basClearanceSNC.stt"
			SPC1L_clear_underway(seqg_env);
# line 87 "../spc1basClearanceSNC.stt"
			SPC1L_update_report(seqg_env, B42ON);
		}
		return;
	}
}

/****** Code for state "watchman_42_released" in state set "SPC1L_clearance_status" ******/

/* Event function for state "watchman_42_released" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_watchman_42_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 93 "../spc1basClearanceSNC.stt"
	if (SPC1_W42_STS == FAIL)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 97 "../spc1basClearanceSNC.stt"
	if (SPC1_W42_STS != B42ON)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_42_released" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_watchman_42_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 98 "../spc1basClearanceSNC.stt"
			SPC1L_update_report(seqg_env, DA005OFF);
		}
		return;
	}
}

/****** Code for state "door_a005_closed" in state set "SPC1L_clearance_status" ******/

/* Event function for state "door_a005_closed" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_door_a005_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 104 "../spc1basClearanceSNC.stt"
	if (SPC1_W42_STS == FAIL)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 109 "../spc1basClearanceSNC.stt"
	if (SPC1_W43_STS != DA005OFF)
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "door_a005_closed" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_door_a005_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 110 "../spc1basClearanceSNC.stt"
			SPC1L_update_report(seqg_env, B43OFF);
# line 111 "../spc1basClearanceSNC.stt"
			printf("Watchman 43 must be activated\n");
		}
		return;
	}
}

/****** Code for state "watchman_43_pressed" in state set "SPC1L_clearance_status" ******/

/* Event function for state "watchman_43_pressed" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_watchman_43_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 118 "../spc1basClearanceSNC.stt"
	if (SPC1_W42_STS == FAIL)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 123 "../spc1basClearanceSNC.stt"
	if (!SPC1_W43_STS)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_43_pressed" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_watchman_43_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 125 "../spc1basClearanceSNC.stt"
			SPC1L_status(seqg_env);
		}
		return;
	}
}

/****** Code for state "clearance_faillures" in state set "SPC1L_clearance_status" ******/

/* Entry function for state "clearance_faillures" in state set "SPC1L_clearance_status" */
static void seqg_entry_SPC1L_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 133 "../spc1basClearanceSNC.stt"
	printf("SPC1 LOW CLEARANCE FAILURE CONDITION: ");
# line 134 "../spc1basClearanceSNC.stt"
	spc1LUpdate = FALSE;
}

/* Exit function for state "clearance_faillures" in state set "SPC1L_clearance_status" */
static void seqg_exit_SPC1L_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 142 "../spc1basClearanceSNC.stt"
	SPC1L_OLD_FAIL_COND = SPC1L_FAIL_COND;
}

/* Event function for state "clearance_faillures" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_clearance_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_faillures" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_clearance_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 138 "../spc1basClearanceSNC.stt"
			SPC1L_update_failed(seqg_env, SPC1L_FAIL_COND);
		}
		return;
	}
}

/****** Code for state "vc_faillures" in state set "SPC1L_clearance_status" ******/

/* Entry function for state "vc_faillures" in state set "SPC1L_clearance_status" */
static void seqg_entry_SPC1L_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 150 "../spc1basClearanceSNC.stt"
	printf("SPC1 LOW CLEAR FAILURE CONDITION: ");
# line 151 "../spc1basClearanceSNC.stt"
	spc1LUpdate = FALSE;
}

/* Exit function for state "vc_faillures" in state set "SPC1L_clearance_status" */
static void seqg_exit_SPC1L_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 159 "../spc1basClearanceSNC.stt"
	SPC1L_OLD_FAIL_COND = SPC1L_FAIL_COND;
}

/* Event function for state "vc_faillures" in state set "SPC1L_clearance_status" */
static seqBool seqg_event_SPC1L_clearance_status_0_vc_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 154 "../spc1basClearanceSNC.stt"
	if (SPC1L_VC)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vc_faillures" in state set "SPC1L_clearance_status" */
static void seqg_action_SPC1L_clearance_status_0_vc_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 155 "../spc1basClearanceSNC.stt"
			SPC1L_update_failed(seqg_env, SPC1L_VC);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{SYS}:SPC1L-CLR-STATS", (size_t)&SPC1L_CLR_STATS, "SPC1L_CLR_STATS", P_STRING, 1, 1, 0, 0, 0, 0},
	{"{SYS}:SPC1L-INTLCK-STATS", (size_t)&SPC1L_INTLCK_STATS, "SPC1L_INTLCK_STATS", P_STRING, 1, 2, 0, 0, 0, 0},
	{"{SYS}:SPC1L-VC", (size_t)&SPC1L_VC, "SPC1L_VC", P_SHORT, 1, 3, 0, 1, 0, 0},
	{"{SYS}:SPC1-W42-STS", (size_t)&SPC1_W42_STS, "SPC1_W42_STS", P_SHORT, 1, 4, 0, 1, 0, 0},
	{"{SYS}:SPC1-W43-STS", (size_t)&SPC1_W43_STS, "SPC1_W43_STS", P_SHORT, 1, 5, 0, 1, 0, 0},
	{"{SYS}:SPC1L-FAIL-COND", (size_t)&SPC1L_FAIL_COND, "SPC1L_FAIL_COND", P_SHORT, 1, 6, 0, 1, 0, 0},
	{"{SYS}:SPC1L-INIT", (size_t)&SPC1L_INIT, "SPC1L_INIT", P_SHORT, 1, 7, 0, 0, 0, 0},
};

/* Event masks for state set "SPC1L_clearance_status" */
static const seqMask seqg_mask_SPC1L_clearance_status_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_vault_cleared[] = {
	0x00000008,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_recover_faillure[] = {
	0x00000040,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_watchman_42_pressed[] = {
	0x00000010,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_watchman_42_released[] = {
	0x00000010,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_door_a005_closed[] = {
	0x00000030,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_watchman_43_pressed[] = {
	0x00000030,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_clearance_faillures[] = {
	0x00000000,
};
static const seqMask seqg_mask_SPC1L_clearance_status_0_vc_faillures[] = {
	0x00000008,
};

/* State table for state set "SPC1L_clearance_status" */
static seqState seqg_states_SPC1L_clearance_status[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_SPC1L_clearance_status_0_init,
	/* event function */    seqg_event_SPC1L_clearance_status_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "vault_cleared",
	/* action function */   seqg_action_SPC1L_clearance_status_0_vault_cleared,
	/* event function */    seqg_event_SPC1L_clearance_status_0_vault_cleared,
	/* entry function */    seqg_entry_SPC1L_clearance_status_0_vault_cleared,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_vault_cleared,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "recover_faillure",
	/* action function */   seqg_action_SPC1L_clearance_status_0_recover_faillure,
	/* event function */    seqg_event_SPC1L_clearance_status_0_recover_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_recover_faillure,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_42_pressed",
	/* action function */   seqg_action_SPC1L_clearance_status_0_watchman_42_pressed,
	/* event function */    seqg_event_SPC1L_clearance_status_0_watchman_42_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_watchman_42_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_42_released",
	/* action function */   seqg_action_SPC1L_clearance_status_0_watchman_42_released,
	/* event function */    seqg_event_SPC1L_clearance_status_0_watchman_42_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_watchman_42_released,
	/* state options */     (0)
	},
	{
	/* state name */        "door_a005_closed",
	/* action function */   seqg_action_SPC1L_clearance_status_0_door_a005_closed,
	/* event function */    seqg_event_SPC1L_clearance_status_0_door_a005_closed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_door_a005_closed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_43_pressed",
	/* action function */   seqg_action_SPC1L_clearance_status_0_watchman_43_pressed,
	/* event function */    seqg_event_SPC1L_clearance_status_0_watchman_43_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_watchman_43_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "clearance_faillures",
	/* action function */   seqg_action_SPC1L_clearance_status_0_clearance_faillures,
	/* event function */    seqg_event_SPC1L_clearance_status_0_clearance_faillures,
	/* entry function */    seqg_entry_SPC1L_clearance_status_0_clearance_faillures,
	/* exit function */     seqg_exit_SPC1L_clearance_status_0_clearance_faillures,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_clearance_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "vc_faillures",
	/* action function */   seqg_action_SPC1L_clearance_status_0_vc_faillures,
	/* event function */    seqg_event_SPC1L_clearance_status_0_vc_faillures,
	/* entry function */    seqg_entry_SPC1L_clearance_status_0_vc_faillures,
	/* exit function */     seqg_exit_SPC1L_clearance_status_0_vc_faillures,
	/* event mask array */  seqg_mask_SPC1L_clearance_status_0_vc_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "SPC1L_clearance_status",
	/* states */            seqg_states_SPC1L_clearance_status,
	/* number of states */  9
	},
};

/* Program table (global) */
seqProgram spc1basClearanceSNC = {
	/* magic number */      2002001,
	/* program name */      "spc1basClearanceSNC",
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
# line 164 "../spc1basClearanceSNC.stt"
static void initVault(SS_ID seqg_env)
{
# line 165 "../spc1basClearanceSNC.stt"
	SPC1L_INIT = TRUE;
# line 166 "../spc1basClearanceSNC.stt"
	not_cleared(SPC1L_CLR_STATS);
# line 167 "../spc1basClearanceSNC.stt"
	report_error(SPC1L_INTLCK_STATS, 0);
# line 168 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SPC1L_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 169 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SPC1L_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 170 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 6/*SPC1L_INIT*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 173 "../spc1basClearanceSNC.stt"
static void SPC1L_update_failed(SS_ID seqg_env, short report)
{
# line 175 "../spc1basClearanceSNC.stt"
	clear_failed(SPC1L_CLR_STATS);
# line 176 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SPC1L_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 177 "../spc1basClearanceSNC.stt"
	report_error(SPC1L_INTLCK_STATS, report);
# line 178 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SPC1L_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 179 "../spc1basClearanceSNC.stt"
	printf("%s%s%s\n", ERROR, SPC1L_INTLCK_STATS, DEF);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 182 "../spc1basClearanceSNC.stt"
static void SPC1L_update_report(SS_ID seqg_env, short intlck)
{
# line 183 "../spc1basClearanceSNC.stt"
	report_error(SPC1L_INTLCK_STATS, intlck);
# line 184 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SPC1L_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 187 "../spc1basClearanceSNC.stt"
static void SPC1L_status(SS_ID seqg_env)
{
# line 189 "../spc1basClearanceSNC.stt"
	cleared(SPC1L_CLR_STATS);
# line 190 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SPC1L_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 191 "../spc1basClearanceSNC.stt"
	report_error(SPC1L_INTLCK_STATS, 0);
# line 192 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SPC1L_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 195 "../spc1basClearanceSNC.stt"
static void SPC1L_clear_underway(SS_ID seqg_env)
{
# line 197 "../spc1basClearanceSNC.stt"
	clear_underway(SPC1L_CLR_STATS);
# line 198 "../spc1basClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SPC1L_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

/* Register sequencer commands and program */
#include "epicsExport.h"
static void spc1basClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&spc1basClearanceSNC);
}
epicsExportRegistrar(spc1basClearanceSNCRegistrar);
