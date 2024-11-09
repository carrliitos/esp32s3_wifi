/*
 * rgb_led.h
 *
 * Created on: 2024-11-09
 *     Author: Benzon Carlitos Salazar
 */

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

// RGD LED GPIOs
#define RGB_LED_RED_GPIO   19
#define RGB_LED_GREEN_GPIO 20
#define RGB_LED_BLUE_GPIO  21

// RGB LED color mix channels
#define RGB_LED_CHANNEL_NUM 3

// RGB LED configuration
typedef struct {
  int channel;
  int gpio;
  int mode;
  int timer_index;
} ledc_info_t;

/**
 * Color to indicate WiFi application has started.
 */
void rgb_led_wifi_app_started(void);

/**
 * Color to indicate HTTP server has started.
 */
void rgb_led_http_server_started(void);

/**
 * Color to indicate that the ESP32 is connected to an access point.
 */
void rgb_led_wifi_connected(void);

#endif /* MAIN_RGB_LED_H_ */
