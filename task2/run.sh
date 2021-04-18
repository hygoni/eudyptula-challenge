qemu-system-x86_64 \
        -cpu host \
        -smp 4 \
        -enable-kvm -m 512 \
        -kernel ./bzImage \
        -append "console=ttyS0 init=/init" \
	-initrd ./initramfs-busybox.cpio.gz \
	-nographic
