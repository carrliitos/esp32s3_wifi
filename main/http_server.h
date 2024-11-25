/*
 * http_server.h
 *
 * Created on:         2024-11-16 11:34:11
 *     Author:         carrliitos (benzon.salazar@gmail.com)
 *
 * Last Modified by:   carrliitos
 * Last Modified time: 2024-11-25 17:32:19
 */

#ifndef MAIN_HTTP_SERVER_H
#define MAIN_HTTP_SERVER_H


/**
 * Messages for the HTTP monitor
 */
typedef enum http_server_message {
  HTTP_MESSAGE_WIFI_CONNECT_INIT = 0,
  HTTP_MESSAGE_WIFI_CONNECT_SUCCESS,
  HTTP_MESSAGE_WIFI_CONNECT_FAIL,
  HTTP_MESSAGE_OTA_UPDATE_SUCCESSFUL,
  HTTP_MESSAGE_OTA_UPDATE_FAILED,
  HTTP_MESSAGE_OTA_UPDATE_INITIALIZED
} http_server_message_e;

/**
 * Structure for the message queue
 */
typedef struct http_server_queue_message {
  http_server_message msgID;
} http_server_queue_message_t;

/**
 * Sends a message to the queue
 * @param msgID message ID from the http_server_message_e enum.
 * @return pdTRUE if an item was successfully sent to the queue, other pdFALSE.
 * @note Expand the parameter list based on requirements, e.g., how we've expanded the http_server_queue_message_t.
 */
BaseType_t http_server_monitor_send_message(http_server_message_e msgID);

/**
 * Starts the HTTP Server.
 */
void http_server_start(void);

/**
 * Stops the HTTP Server.
 */
void http_server_stop(void);

#endif /* MAIN_HTTP_SERVER_H */