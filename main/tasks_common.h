/*
 * tasks_common.h
 *
 * Created on:         2024-11-09 11:34:53
 *     Author:         carrliitos (benzon.salazar@gmail.com)
 *
 * Last Modified by:   carrliitos
 * Last Modified time: 2024-11-16 11:35:24
 */

#ifndef MAIN_TASKS_COMMON_H_
#define MAIN_TASKS_COMMON_H_

// WiFi application task
#define WIFI_APP_TASK_STACK_SIZE 4096
#define WIFI_APP_TASK_PRIORITY   5
#define WIFI_APP_TASK_CORE_ID    0

// HTTP Server task info
#define HTTP_SERVER_TASK_STACK_SIZE 8912
#define HTTP_SERVER_TASK_PRIORITY   4
#define HTTP_SERVER_TASK_CORE_ID    0

// HTTP Server monitor task info
#define HTTP_SERVER_MONITOR_STACK_SIZE 4096
#define HTTP_SERVER_MONITOR_PRIORITY   3
#define HTTP_SERVER_MONITOR_CORE_ID    0

#endif /* MAIN_TASKS_COMMON_H_ */