#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/mavlink_passthrough/mavlink_passthrough.h>
#include <mavlink/common/mavlink.h>

using namespace mavsdk;

struct Mission {};

int main() {
    Mavsdk mavsdk;
    auto conn_res = mavsdk.add_any_connection("/dev/ttyUSB0:57600");
    if (conn_res != ConnectionResult::Success) return 1;

    // Wait for system
    while (mavsdk.systems().empty()) std::this_thread::sleep_for(std::chrono::seconds(1));
    auto system = mavsdk.systems().at(0);

    MavlinkPassthrough passthrough(system);

    // Fill a STATUSTEXT message
    mavlink_message_t msg;
    mavlink_msg_statustext_pack(
        255, 0, &msg,
        MAV_SEVERITY_INFO,
        "Hello from MAVSDK!",
        true
    );

    passthrough.send_message(msg);

    return 0;
}
