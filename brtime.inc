/*
 * Copyright (C) 2024 DeviceBlack
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	 http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// brtime - Biblioteca para manipulação de datas e horas no fuso horário do Brasil.

#if defined _brtime_included
	#endinput
#endif
#define _brtime_included

static DB:brtime_db, DBResult:brtime_rs;

#if defined FILTERSCRIPT
	/*
	 * OnFilterScriptInit - Inicializa a biblioteca brtime durante o carregamento.
	 *
	 * Retorno: 1 caso o gancho RT_FilterScriptInit não seja declarado
	 */
	public OnFilterScriptInit() {
		brtime_db = db_open(".brtime");
		
		#if defined RT_FilterScriptInit
			return RT_FilterScriptInit();
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit RT_FilterScriptInit
	#if defined RT_FilterScriptInit
		forward RT_FilterScriptInit();
	#endif
#else
	/*
	 * OnGameModeInit - Inicializa a biblioteca brtime durante o carregamento.
	 *
	 * Retorno: 1 caso o gancho RT_GameModeInit não seja declarado
	 */
	public OnGameModeInit() {
		brtime_db = db_open(".brtime");
		
		#if defined RT_GameModeInit
			return RT_GameModeInit();
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit RT_GameModeInit
	#if defined RT_GameModeInit
		forward RT_GameModeInit();
	#endif
#endif

/*
 * BR_GetDate - Obtém a data atual no fuso horário do Brasil.
 *
 * Parâmetros:
 *   &year   - Referência para armazenar o ano.
 *   &month  - Referência para armazenar o mês.
 *   &day	- Referência para armazenar o dia.
 *
 * Retorna: O número de dias desde a Época Unix até a data atual no fuso horário do Brasil.
 */
forward BR_GetDate(&year=0, &month=0, &day=0);
stock BR_GetDate(&year=0, &month=0, &day=0) {
	brtime_rs = db_query(
		brtime_db,
		"SELECT strftime('%Y', 'now', '-3 hours') AS Year,"
		"strftime('%m', 'now', '-3 hours') AS Month,"
		"strftime('%d', 'now', '-3 hours') AS Day;"
	);
	
	year = db_get_field_int(brtime_rs, 0);
	month = db_get_field_int(brtime_rs, 1);
	day = db_get_field_int(brtime_rs, 2);
	return ((gettime() - 10800) / 86400);
}

/*
 * BR_GetTime - Obtém a hora atual no fuso horário do Brasil.
 *
 * Parâmetros:
 *   &hour   - Referência para armazenar a hora.
 *   &minute - Referência para armazenar os minutos.
 *   &second - Referência para armazenar os segundos.
 *
 * Retorna: O número de segundos desde a Época Unix até a hora atual no fuso horário do Brasil.
 */
forward BR_GetTime(&hour=0, &minute=0, &second=0);
stock BR_GetTime(&hour=0, &minute=0, &second=0) {
	brtime_rs = db_query(
		brtime_db,
		"SELECT strftime('%H', 'now', '-3 hours') AS Hour,"
		"strftime('%M', 'now', '-3 hours') AS Minute,"
		"strftime('%S', 'now', '-3 hours') AS Second;"
	);
	
	hour = db_get_field_int(brtime_rs, 0);
	minute = db_get_field_int(brtime_rs, 1);
	second = db_get_field_int(brtime_rs, 2);
	return (gettime() - 10800);
}
