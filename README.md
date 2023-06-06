# test-systemd-mainpid-openfile
Just a test.

I tried to set MAINPID by letting the process write to a passed in FD (from the systemd directive `OpenFile=`)
but I couldn't get it to work.

I tried both with and without closing the file descriptor.

Not prividing much details, but just leaving some code here if anyone wants to experiment.



```
(cd container && podman build -q -t gxx .)
podman run --rm -v ./:/src:Z localhost/gxx g++ -o /src/ready -lsystemd  -std=c++20 /src/notifyready.cpp && cp ready /var/tmp/ready
chcon system_u:object_r:bin_t:s0 /var/tmp/ready
```


