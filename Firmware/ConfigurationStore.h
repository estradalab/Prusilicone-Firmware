#ifndef CONFIG_STORE_H
#define CONFIG_STORE_H
#define EEPROM_SETTINGS

#include "Configuration.h"
#include <stdint.h>
#include <avr/eeprom.h>

typedef struct
{
    char version[4];
    float axis_steps_per_mm[5];
    float max_feedrate_normal[5];
    uint32_t max_acceleration_mm_per_s2_normal[5];
    float acceleration; //!< Normal acceleration mm/s^2  THIS IS THE DEFAULT ACCELERATION for all moves. M204 SXXXX
    float retract_acceleration; //!< mm/s^2 filament pull-pack and push-forward while standing still in the other axis M204 TXXXX
    float minimumfeedrate;
    float mintravelfeedrate;
    uint32_t min_segment_time_us; //!< (µs) M205 B
    float max_jerk[5]; //!< Jerk is a maximum immediate velocity change.
    float add_homing[3];
    float zprobe_zoffset; //!< Only used with define ENABLE_AUTO_BED_LEVELING
    float Kp;
    float Ki;
    float Kd;
    float bedKp;
    float bedKi;
    float bedKd;
    int lcd_contrast; //!< unused
    bool autoretract_enabled;
    float retract_length;
    float retract_feedrate;
    float retract_zlift;
    float retract_recover_length;
    float retract_recover_feedrate;
    bool volumetric_enabled;
    float filament_size[2]; //!< cross-sectional area of filament (in millimeters), typically around 1.75 or 2.85, 0 disables the volumetric calculations for the extruder.
    float max_feedrate_silent[5]; //!< max speeds for silent mode
    uint32_t max_acceleration_mm_per_s2_silent[5];
    unsigned char axis_ustep_resolution[5];
    float travel_acceleration; //!< travel acceleration mm/s^2
    // Arc Interpolation Settings, configurable via M214
    float mm_per_arc_segment;
    float min_mm_per_arc_segment;
    uint8_t n_arc_correction; // If equal to zero, this is disabled
    uint16_t min_arc_segments; // If equal to zero, this is disabled
    uint16_t arc_segments_per_sec; // If equal to zero, this is disabled
} M500_conf;

extern M500_conf cs;

void Config_ResetDefault();

#ifndef DISABLE_M503
void Config_PrintSettings(uint8_t level = 0);
#else
FORCE_INLINE void Config_PrintSettings() {}
#endif

#ifdef EEPROM_SETTINGS
void Config_StoreSettings();
bool Config_RetrieveSettings();
#else
FORCE_INLINE void Config_StoreSettings() {}
FORCE_INLINE void Config_RetrieveSettings() { Config_ResetDefault(); Config_PrintSettings(); }
#endif

#endif//CONFIG_STORE_H
