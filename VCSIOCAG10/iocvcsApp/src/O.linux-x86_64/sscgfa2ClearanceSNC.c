/* C code for program sscgfa2ClearanceSNC, generated by snc from ../sscgfa2ClearanceSNC.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../sscgfa2ClearanceSNC.stt"

/*******************************************************************/
#include "vcs_var_mes.h" // define this here so C functions are seen
/*******************************************************************/
#define	VCOK       	0
#define FAIL		-1
#define B13ON 		50	      
#define B14OFF		51          
#define B14ON		53 		
#define B15OFF		56 
#define DA1ON 		41	        
#define DA1S1OFF	54	             
#define DA1S2OFF	54	



/* Variable declarations */
# line 19 "../sscgfa2ClearanceSNC.stt"
static	short SSCA2_INIT;
# line 20 "../sscgfa2ClearanceSNC.stt"
static	short SSCA2_VC;
# line 21 "../sscgfa2ClearanceSNC.stt"
static	short SSC_W13_STS;
# line 22 "../sscgfa2ClearanceSNC.stt"
static	short SSC_W14_STS;
# line 23 "../sscgfa2ClearanceSNC.stt"
static	short SSC_W15_STS;
# line 24 "../sscgfa2ClearanceSNC.stt"
static	short SSCA2_FAIL_COND;
# line 25 "../sscgfa2ClearanceSNC.stt"
static	string SSCA2_CLR_STATS;
# line 26 "../sscgfa2ClearanceSNC.stt"
static	string SSCA2_INTLCK_STATS;
# line 28 "../sscgfa2ClearanceSNC.stt"
static	short SSCA2Update;
# line 29 "../sscgfa2ClearanceSNC.stt"
static	short SSCA2_OLD_FAIL_COND;


/* Function declarations */
# line 198 "../sscgfa2ClearanceSNC.stt"
static void initVault(SS_ID seqg_env);
# line 208 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_update_failed(SS_ID seqg_env, short report);
# line 217 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_update_report(SS_ID seqg_env, short intlck);
# line 222 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_status(SS_ID seqg_env);
# line 230 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_clear_underway(SS_ID seqg_env);

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "init" in state set "SSCA2_clearance_status" ******/

/* Event function for state "init" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 50 "../sscgfa2ClearanceSNC.stt"
	if (seq_delay(seqg_env, 2.5))
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 51 "../sscgfa2ClearanceSNC.stt"
			initVault(seqg_env);
# line 52 "../sscgfa2ClearanceSNC.stt"
			printf("%sSSC GROUND FLOOR AREA 2 INITIALISATION COMPLETED%s\n", OK, DEF);
		}
		return;
	}
}

/****** Code for state "vault_cleared" in state set "SSCA2_clearance_status" ******/

/* Entry function for state "vault_cleared" in state set "SSCA2_clearance_status" */
static void seqg_entry_SSCA2_clearance_status_0_vault_cleared(SS_ID seqg_env)
{
# line 60 "../sscgfa2ClearanceSNC.stt"
	printf("%sSSC GROUND FLOOR AREA 2 IN CLEARED STATE%s\n", CLR, DEF);
}

/* Event function for state "vault_cleared" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_vault_cleared(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 62 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_VC != VCOK)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vault_cleared" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_vault_cleared(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "recover_faillure" in state set "SSCA2_clearance_status" ******/

/* Event function for state "recover_faillure" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_recover_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 69 "../sscgfa2ClearanceSNC.stt"
	if (!SSCA2_FAIL_COND)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 76 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_FAIL_COND != SSCA2_OLD_FAIL_COND)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_faillure" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_recover_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 70 "../sscgfa2ClearanceSNC.stt"
			if (!SSCA2Update)
			{
# line 71 "../sscgfa2ClearanceSNC.stt"
				printf("%sRECOVERING FROM FAILLURE - ENTERING W13 STATE%s\n", OK, DEF);
# line 72 "../sscgfa2ClearanceSNC.stt"
				SSCA2Update = TRUE;
			}
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "watchman_13_pressed" in state set "SSCA2_clearance_status" ******/

/* Event function for state "watchman_13_pressed" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_watchman_13_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 83 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_FAIL_COND != VCOK)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 87 "../sscgfa2ClearanceSNC.stt"
	if (SSC_W13_STS == B13ON)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_13_pressed" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_watchman_13_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 84 "../sscgfa2ClearanceSNC.stt"
			SSCA2_OLD_FAIL_COND = SSCA2_FAIL_COND;
		}
		return;
	case 1:
		{
# line 88 "../sscgfa2ClearanceSNC.stt"
			SSCA2_clear_underway(seqg_env);
# line 89 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_report(seqg_env, B13ON);
		}
		return;
	}
}

/****** Code for state "watchman_13_released" in state set "SSCA2_clearance_status" ******/

/* Event function for state "watchman_13_released" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_watchman_13_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 95 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_FAIL_COND != VCOK)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 99 "../sscgfa2ClearanceSNC.stt"
	if (SSC_W13_STS != B13ON)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_13_released" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_watchman_13_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 100 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_report(seqg_env, B14OFF);
		}
		return;
	}
}

/****** Code for state "watchman_14_pressed" in state set "SSCA2_clearance_status" ******/

/* Event function for state "watchman_14_pressed" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_watchman_14_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 107 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_FAIL_COND != VCOK)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 112 "../sscgfa2ClearanceSNC.stt"
	if (SSC_W14_STS == B14ON)
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_14_pressed" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_watchman_14_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 113 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_report(seqg_env, B14ON);
		}
		return;
	}
}

/****** Code for state "watchman_14_released" in state set "SSCA2_clearance_status" ******/

/* Event function for state "watchman_14_released" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_watchman_14_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 119 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_FAIL_COND != VCOK)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 123 "../sscgfa2ClearanceSNC.stt"
	if (SSC_W14_STS != B14ON)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_14_released" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_watchman_14_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
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

/****** Code for state "door_a1_closed" in state set "SSCA2_clearance_status" ******/

/* Event function for state "door_a1_closed" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_door_a1_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 131 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_FAIL_COND != VCOK)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 135 "../sscgfa2ClearanceSNC.stt"
	if (SSC_W15_STS == DA1S1OFF)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 139 "../sscgfa2ClearanceSNC.stt"
	if (SSC_W15_STS == DA1S2OFF)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 2;
		return TRUE;
	}
	if (TRUE)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 3;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "door_a1_closed" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_door_a1_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 136 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_report(seqg_env, DA1S1OFF);
		}
		return;
	case 2:
		{
# line 140 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_report(seqg_env, DA1S2OFF);
		}
		return;
	case 3:
		{
# line 144 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_report(seqg_env, B15OFF);
		}
		return;
	}
}

/****** Code for state "watchman_15_pressed" in state set "SSCA2_clearance_status" ******/

/* Event function for state "watchman_15_pressed" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_watchman_15_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 150 "../sscgfa2ClearanceSNC.stt"
	if (SSCA2_FAIL_COND != VCOK)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 155 "../sscgfa2ClearanceSNC.stt"
	if (!SSC_W15_STS)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_15_pressed" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_watchman_15_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 157 "../sscgfa2ClearanceSNC.stt"
			SSCA2_status(seqg_env);
		}
		return;
	}
}

/****** Code for state "clearance_faillures" in state set "SSCA2_clearance_status" ******/

/* Entry function for state "clearance_faillures" in state set "SSCA2_clearance_status" */
static void seqg_entry_SSCA2_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 166 "../sscgfa2ClearanceSNC.stt"
	printf("SSC GF A2 CLEARANCE FAILURE CONDITION: ");
# line 167 "../sscgfa2ClearanceSNC.stt"
	SSCA2Update = FALSE;
}

/* Exit function for state "clearance_faillures" in state set "SSCA2_clearance_status" */
static void seqg_exit_SSCA2_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 175 "../sscgfa2ClearanceSNC.stt"
	SSCA2_OLD_FAIL_COND = SSCA2_FAIL_COND;
}

/* Event function for state "clearance_faillures" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_clearance_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_faillures" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_clearance_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 171 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_failed(seqg_env, SSCA2_FAIL_COND);
		}
		return;
	}
}

/****** Code for state "vc_faillures" in state set "SSCA2_clearance_status" ******/

/* Entry function for state "vc_faillures" in state set "SSCA2_clearance_status" */
static void seqg_entry_SSCA2_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 184 "../sscgfa2ClearanceSNC.stt"
	printf("SSC GF A2 CLEAR FAILURE CONDITION: ");
# line 185 "../sscgfa2ClearanceSNC.stt"
	SSCA2Update = FALSE;
}

/* Exit function for state "vc_faillures" in state set "SSCA2_clearance_status" */
static void seqg_exit_SSCA2_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 193 "../sscgfa2ClearanceSNC.stt"
	SSCA2_OLD_FAIL_COND = SSCA2_FAIL_COND;
}

/* Event function for state "vc_faillures" in state set "SSCA2_clearance_status" */
static seqBool seqg_event_SSCA2_clearance_status_0_vc_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vc_faillures" in state set "SSCA2_clearance_status" */
static void seqg_action_SSCA2_clearance_status_0_vc_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 189 "../sscgfa2ClearanceSNC.stt"
			SSCA2_update_failed(seqg_env, SSCA2_VC);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{SYS}:SSCA2-CLR-STATS", (size_t)&SSCA2_CLR_STATS, "SSCA2_CLR_STATS", P_STRING, 1, 1, 0, 0, 0, 0},
	{"{SYS}:SSCA2-INTLCK-STATS", (size_t)&SSCA2_INTLCK_STATS, "SSCA2_INTLCK_STATS", P_STRING, 1, 2, 0, 0, 0, 0},
	{"{SYS}:SSCA2-VC", (size_t)&SSCA2_VC, "SSCA2_VC", P_SHORT, 1, 3, 0, 1, 0, 0},
	{"{SYS}:SSCA2-INIT", (size_t)&SSCA2_INIT, "SSCA2_INIT", P_SHORT, 1, 4, 0, 0, 0, 0},
	{"{SYS}:SSC-W13-STS", (size_t)&SSC_W13_STS, "SSC_W13_STS", P_SHORT, 1, 5, 0, 1, 0, 0},
	{"{SYS}:SSC-W14-STS", (size_t)&SSC_W14_STS, "SSC_W14_STS", P_SHORT, 1, 6, 0, 1, 0, 0},
	{"{SYS}:SSC-W15-STS", (size_t)&SSC_W15_STS, "SSC_W15_STS", P_SHORT, 1, 7, 0, 1, 0, 0},
	{"{SYS}:SSCA2-FAIL-COND", (size_t)&SSCA2_FAIL_COND, "SSCA2_FAIL_COND", P_SHORT, 1, 8, 0, 1, 0, 0},
};

/* Event masks for state set "SSCA2_clearance_status" */
static const seqMask seqg_mask_SSCA2_clearance_status_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_vault_cleared[] = {
	0x00000008,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_recover_faillure[] = {
	0x00000100,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_watchman_13_pressed[] = {
	0x00000120,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_watchman_13_released[] = {
	0x00000120,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_watchman_14_pressed[] = {
	0x00000140,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_watchman_14_released[] = {
	0x00000140,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_door_a1_closed[] = {
	0x00000180,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_watchman_15_pressed[] = {
	0x00000180,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_clearance_faillures[] = {
	0x00000000,
};
static const seqMask seqg_mask_SSCA2_clearance_status_0_vc_faillures[] = {
	0x00000000,
};

/* State table for state set "SSCA2_clearance_status" */
static seqState seqg_states_SSCA2_clearance_status[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_SSCA2_clearance_status_0_init,
	/* event function */    seqg_event_SSCA2_clearance_status_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "vault_cleared",
	/* action function */   seqg_action_SSCA2_clearance_status_0_vault_cleared,
	/* event function */    seqg_event_SSCA2_clearance_status_0_vault_cleared,
	/* entry function */    seqg_entry_SSCA2_clearance_status_0_vault_cleared,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_vault_cleared,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "recover_faillure",
	/* action function */   seqg_action_SSCA2_clearance_status_0_recover_faillure,
	/* event function */    seqg_event_SSCA2_clearance_status_0_recover_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_recover_faillure,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_13_pressed",
	/* action function */   seqg_action_SSCA2_clearance_status_0_watchman_13_pressed,
	/* event function */    seqg_event_SSCA2_clearance_status_0_watchman_13_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_watchman_13_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_13_released",
	/* action function */   seqg_action_SSCA2_clearance_status_0_watchman_13_released,
	/* event function */    seqg_event_SSCA2_clearance_status_0_watchman_13_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_watchman_13_released,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_14_pressed",
	/* action function */   seqg_action_SSCA2_clearance_status_0_watchman_14_pressed,
	/* event function */    seqg_event_SSCA2_clearance_status_0_watchman_14_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_watchman_14_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_14_released",
	/* action function */   seqg_action_SSCA2_clearance_status_0_watchman_14_released,
	/* event function */    seqg_event_SSCA2_clearance_status_0_watchman_14_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_watchman_14_released,
	/* state options */     (0)
	},
	{
	/* state name */        "door_a1_closed",
	/* action function */   seqg_action_SSCA2_clearance_status_0_door_a1_closed,
	/* event function */    seqg_event_SSCA2_clearance_status_0_door_a1_closed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_door_a1_closed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_15_pressed",
	/* action function */   seqg_action_SSCA2_clearance_status_0_watchman_15_pressed,
	/* event function */    seqg_event_SSCA2_clearance_status_0_watchman_15_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_watchman_15_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "clearance_faillures",
	/* action function */   seqg_action_SSCA2_clearance_status_0_clearance_faillures,
	/* event function */    seqg_event_SSCA2_clearance_status_0_clearance_faillures,
	/* entry function */    seqg_entry_SSCA2_clearance_status_0_clearance_faillures,
	/* exit function */     seqg_exit_SSCA2_clearance_status_0_clearance_faillures,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_clearance_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "vc_faillures",
	/* action function */   seqg_action_SSCA2_clearance_status_0_vc_faillures,
	/* event function */    seqg_event_SSCA2_clearance_status_0_vc_faillures,
	/* entry function */    seqg_entry_SSCA2_clearance_status_0_vc_faillures,
	/* exit function */     seqg_exit_SSCA2_clearance_status_0_vc_faillures,
	/* event mask array */  seqg_mask_SSCA2_clearance_status_0_vc_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "SSCA2_clearance_status",
	/* states */            seqg_states_SSCA2_clearance_status,
	/* number of states */  11
	},
};

/* Program table (global) */
seqProgram sscgfa2ClearanceSNC = {
	/* magic number */      2002001,
	/* program name */      "sscgfa2ClearanceSNC",
	/* channels */          seqg_chans,
	/* num. channels */     8,
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
# line 198 "../sscgfa2ClearanceSNC.stt"
static void initVault(SS_ID seqg_env)
{
# line 199 "../sscgfa2ClearanceSNC.stt"
	SSCA2_INIT = TRUE;
# line 200 "../sscgfa2ClearanceSNC.stt"
	SSCA2_OLD_FAIL_COND = SSCA2_FAIL_COND;
# line 201 "../sscgfa2ClearanceSNC.stt"
	not_cleared(SSCA2_CLR_STATS);
# line 202 "../sscgfa2ClearanceSNC.stt"
	report_error(SSCA2_INTLCK_STATS, 0);
# line 203 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 3/*SSCA2_INIT*/, SYNC, DEFAULT_TIMEOUT);
# line 204 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SSCA2_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 205 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA2_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 208 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_update_failed(SS_ID seqg_env, short report)
{
# line 210 "../sscgfa2ClearanceSNC.stt"
	clear_failed(SSCA2_CLR_STATS);
# line 211 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SSCA2_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 212 "../sscgfa2ClearanceSNC.stt"
	report_error(SSCA2_INTLCK_STATS, report);
# line 213 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA2_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 214 "../sscgfa2ClearanceSNC.stt"
	printf("%s%s%s\n", ERROR, SSCA2_INTLCK_STATS, DEF);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 217 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_update_report(SS_ID seqg_env, short intlck)
{
# line 218 "../sscgfa2ClearanceSNC.stt"
	report_error(SSCA2_INTLCK_STATS, intlck);
# line 219 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA2_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 222 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_status(SS_ID seqg_env)
{
# line 224 "../sscgfa2ClearanceSNC.stt"
	cleared(SSCA2_CLR_STATS);
# line 225 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SSCA2_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 226 "../sscgfa2ClearanceSNC.stt"
	report_error(SSCA2_INTLCK_STATS, 0);
# line 227 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA2_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 230 "../sscgfa2ClearanceSNC.stt"
static void SSCA2_clear_underway(SS_ID seqg_env)
{
# line 232 "../sscgfa2ClearanceSNC.stt"
	clear_underway(SSCA2_CLR_STATS);
# line 233 "../sscgfa2ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SSCA2_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

/* Register sequencer commands and program */
#include "epicsExport.h"
static void sscgfa2ClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&sscgfa2ClearanceSNC);
}
epicsExportRegistrar(sscgfa2ClearanceSNCRegistrar);