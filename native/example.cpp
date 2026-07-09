#include <sys/mount.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>

// 1. 将你的 Kirin 9030 数据直接硬编码进模块
const char* KIRIN_9030_DATA = R"(Processor	: AArch64 Processor rev 0 (aarch64)
processor	: 0
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd24
CPU revision	: 0
CPU physical	: 0

processor	: 1
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd24
CPU revision	: 0
CPU physical	: 1

processor	: 2
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd24
CPU revision	: 0
CPU physical	: 2

processor	: 3
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd24
CPU revision	: 0
CPU physical	: 3

processor	: 4
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 4

processor	: 5
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 5

processor	: 6
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 6

processor	: 7
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 7

processor	: 8
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 8

processor	: 9
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 9

processor	: 10
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 10

processor	: 11
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd47
CPU revision	: 0
CPU physical	: 11

processor	: 12
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd06
CPU revision	: 0
CPU physical	: 12

processor	: 13
BogoMIPS	: 2000.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm dit uscat ilrcpc flagm ssbs sb paca pacg dcpodp flagm2 frint svei8mm svebf16 i8mm bf16 dgh bti
CPU implementer	: 0x48
CPU architecture: 8
CPU variant	: 0x2
CPU part	: 0xd06
CPU revision	: 0
CPU physical	: 13

Hardware	: HUAWEI Kirin9030
)";

void preAppSpecialize(Api *api, PreAppSpecializeArgs *args) {
    const char *process = api->getProcessName(args); 
    
    // 2. 匹配你想要欺骗的游戏包名
    if (process && (std::string(process) == "com.tencent.tmgp.pubgmhd" || std::string(process) == "com.liuzh.deviceinfo")) {
        
        // 3. 在游戏应用私有的临时目录下创建一个虚假文件（外部应用无权访问此目录，天然隔离）
        std::string fake_path = "/data/data/" + std::string(process) + "/cache/.tmp_info";
        
        int fd = open(fake_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd >= 0) {
            // 将硬编码的麒麟9030数据写入该临时文件
            write(fd, KIRIN_9030_DATA, strlen(KIRIN_9030_DATA));
            close(fd);
            
            // 4. 核心魔术：使用 MS_BIND 将这个刚写好的临时文件挂载到系统的 /proc/cpuinfo 上
            if (mount(fake_path.c_str(), "/proc/cpuinfo", NULL, MS_BIND, NULL) == 0) {
                // 5. 挂载成功后，立刻拔树寻根！把这个临时文件删掉（unlink）
                // 此时 /proc/cpuinfo 已经持有了文件内容，磁盘上的 .tmp_info 彻底消失，无迹可寻
                unlink(fake_path.c_str());
            }
        }
    }
}
