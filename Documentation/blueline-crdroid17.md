# Pixel 3 Android 17 kernel branch

This branch starts at xbill9/android_kernel_google_msm-4.9 commit
`b7e415d5fde554813f558a08209d646ed160fa8d`, preserving the upstream kernel and
backport histories. It contains the 5.4-level eBPF backports, arm64 tracing,
MADV_WIPEONFORK, cpuset-v2-mode and later fixes used by the experimental
Android 16/17 Pixel 3a port. See the existing `backport-tools/` documentation
for upstream testing details and limitations.

Pixel 3 uses `b1c1_defconfig`, not `bonito_defconfig`. This branch enables the
tracing configuration for that Pixel 3 target; its SDM845 hardware drivers,
device trees, display and camera configuration remain those of b1c1.

Build kernel modules together with the kernel. In particular, an old wlan.ko
is not interchangeable with the kernel after the eBPF structure backports.
Android 17 also requires userspace changes; use the matching local manifest:
https://github.com/its-hecker/Blueline-Crdroid-Local-Manifest

Testing of the upstream port on a Pixel 3a is not a successful Pixel 3 boot
test. The actual Linux version remains 4.9; the BPF version property in the
device tree selects backported features and does not upgrade the kernel.

The Pixel 3 configuration disables the unused Smack LSM while retaining SELinux.
The legacy Smack BPF hook in the backport tree references a helper unavailable
in 4.9; it is not used by Android, whose selected/default LSM remains SELinux.
