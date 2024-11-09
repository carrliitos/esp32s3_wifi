/*
 * wifi_app.h
 *
 * Created on: 2024-11-09
 *     Author: Benzon Carlitos Salazar
 */

#ifndef MAIN_WIFI_APP_H
#define MAIN_WIFI_APP_H

#include "esp_netif.h" // Necessary for the network interface objects

// WiFi application settings
#define WIFI_AP_SSID            "ESP32_AP"      // Access Point Name
#define WIFI_AP_PASSWORD        "PASSWORD"      // WiFi Access Point Password
#define WIFI_AP_CHANNEL         1               // Access Point Channel (https://en.wikipedia.org/wiki/List_of_WLAN_channels#2.4_GHz_(802.11b/g/n/ax/be))
#define WIFI_AP_SSID_HIDDEN     0               // Access Point visibility; 0 - visible, 1 - hidden
#define WIFI_AP_MAX_CONNECTIONS 5               // Access Point max clients
#define WIFI_AP_BEACON_INTERVAL 100             // Access Point beacon interval: 100 milliseconds recommended (https://routerguide.net/beacon-interval-best-optimal-setting-improve-wireless-speed/)
#define WIFI_AP_IP              "192.168.0.1"   // Access Point default IP
#define WIFI_AP_GATEWAY         "192.168.0.1"   // Access Point default Gateway (should be the same as IP address)
#define WIFI_AP_NETMASK         "255.255.255.0" // Access Point netmask
#define WIFI_AP_BANDWIDTH       WIFI_BW_HT20    // Access Point bandwidth: 20MHz (https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/wifi.html#wi-fi-ht20-40)
#define WIFI_STA_POWER_SAVE     WIFI_PS_NONE    // Power save not used (https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/wifi.html#esp32-wi-fi-power-saving-mode)
#define MAX_SSID_LENGTH         32              // IEEE standard maximum
#define MAX_PASSWORD_LENGTH     64              // IEEE standard maximum
#define MAX_CONNECTION_RETRIES  5               // Retry number on disconnect

// netif object for the Station and Access Point
extern esp_netif_t* esp_netif_sta; // extern keyword allows for these variables to be visible everywhere
extern esp_netif_t* esp_netif_ap;  // extern keyword allows for these variables to be visible everywhere

/**
 * Message IDs for the WiFi application tasks
 * @note Can be expanded based on application requirements
 */
typedef enum wifi_app_message {
  WIFI_APP_MSG_START_HTTP_SERVER = 0,
  WIFI_APP_MSG_CONNECT_FROM_HTTP_SERVER,
  WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
} wifi_app_message_e;

/**
 * Structure for the message queue.
 * @note Can be expanded based on application requirements (e.g., add another type and paramter as required).
 */
typedef struct wifi_app_queue_message {
  wifi_app_message_e msgID;
} wifi_app_queue_message_t;

/**
 * Sends a message to the queue
 * @param msgID message ID from the wifi_app_message_e
 * @return pdTRUE if an item was successfully sent to the queue, otherwise pdFALSE.
 * @note Can be expanded based on the application requirements (e.g., how we've expanded the wifi_app_queue_message_t).
 */
BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

/**
 * Starts the WiFi RTOS task
 */
void wifi_app_start(void);

#endif /* MAIN_WIFI_APP_H */