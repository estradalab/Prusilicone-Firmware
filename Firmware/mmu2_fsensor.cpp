#include "mmu2_fsensor.h"
#include "Filament_sensor.h"

namespace MMU2 {

FilamentState WhereIsFilament(){
    return FilamentState::AT_FSENSOR; // return fsensor.getFilamentPresent() ? FilamentState::AT_FSENSOR : FilamentState::NOT_PRESENT;
}

} // namespace MMU2
