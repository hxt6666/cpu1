#include <sys/mount.h>
#include <unistd.h>
#include <string>

// 当 Zygote 准备启动应用时触发
void my_zygisk_main(const char* process_name) {
    // 1. 精准锁定：只对特定的游戏包名生效，其他应用不伪装
    if (std::string(process_name) == "com.tencent.tmgp.pubgmhd" || // 举例：和平精英
        std::string(process_name) == "com.liuzh.deviceinfo") {       // 举例：设备信息

        // 2. 核心魔法：使用内核级 bind mount，将伪造的文件挂载到系统的 cpuinfo 上
        // 这一步在应用的独立命名空间内进行，外部根本察觉不到
        const char* fake_cpuinfo = "/data/media/0/.sysdata/my_cpuinfo";
        const char* target_cpuinfo = "/proc/cpuinfo";

        // 执行挂载（需要系统权限，Zygisk 在此时天然拥有）
        mount(fake_cpuinfo, target_cpuinfo, NULL, MS_BIND, NULL);
    }
}
