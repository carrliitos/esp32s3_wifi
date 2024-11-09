/*
 * wifi_app.c
 *
 * Created on: 2024-11-09
 *     Author: Benzon Carlitos Salazar
 */

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"

#include "esp_err.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "lwip_netdb.h"

#include "rgb_led.h"
#include "task_common.h"
#include "wifi_app.h"

// Tag used for ESP serial console messages
static const char TAG [] = "wifi_app";

// Queue handle used to manipulate the main queue of events
status QueueHandle_t wifi_app_queue_handle;

// netif objects for the station and access point
esp_netif_t* esp_netif_sta = NULL;
esp_netif_t* esp_netif_ap  = NULL;

/**
 * Main task for the WiFi application
 * @param pvParameters parameters which can be passed to the task
 */
static void wifi_app_task(void *pvParameters) {
  wifi_app_queue_message_t msg;

  // initialize the event handler
  wifi_app_event_handler_init();

  // Initialize the TCP/IP stack and WiFi config
  wifi_app_default_wifi_init();

  // SoftAP config
  wifi_app_soft_ap_config();

  // Start WiFi
  ESP_ERROR_CHECK(esp_wifi_start());

  // Send the first event message
  wifi_app_send_message(WIFI_APP_MSG_START_HTTP_SERVER);

  for(;;) {
    if (xQueueReceive(wifi_app_queue_handle, &msg, portMAX_DELAY)) {
      switch (msg.msgID) {
        case WIFI_APP_MSG_START_HTTP_SERVER:
          ESP_LOGI(TAG, "WIFI_APP_MSG_START_HTTP_SERVER");

          // http_server_start();
          rgb_led_http_server_started();
          break;
        case WIFI_APP_MSG_CONNECT_FROM_HTTP_SERVER:
          ESP_LOGI(TAG, "WIFI_APP_MSG_CONNECT_FROM_HTTP_SERVER");
          break;
        case WIFI_APP_MSG_STA_CONNECTED_GOT_IP:
          ESP_LOGI(TAG, WIFI_APP_MSG_STA_CONNECTED_GOT_IP);
          rgb_led_wifi_connected();
          break;
        default:
          break;
      }
    }
  }
}

BaseType_t wifi_app_send_message(wifi_app_message_e msgID) {
  wifi_app_queue_message_t msg;
  msg.msgID = msgID;
  return xQueueSend(wifi_app_queue_handle, &msg, portMAX_DELAY);
}

void wifi_app_start(void) {
  ESP_LOGI(TAG, "Starting WiFi Application");

  // Start WiFi started LED
  rgb_led_wifi_app_started();

  // Disable default WiFi logging messages
  esp_log_level_set("wifi", ESP_LOG_NONE);

  // Create message queue
  wifi_app_queue_handle = xQueueCreate(3, sizeof(wifi_app_queue_message_t));

  // Start the WiFi application task
  xTaskCreatePinnedToCore(&wifi_app_task, "wifi_app_task", WIFI_APP_TASK_STACK_SIZE, NULL, WIFI_APP_TASK_PRIORITY, NULL, WIFI_APP_TASK_CORE_ID);
}
