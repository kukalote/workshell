FROM centos:7
MAINTAINER "yalong xun"
ENV container docker
RUN (cd /lib/systemd/system/sysinit.target.wants/; for i in *; do [ $i == \
systemd-tmpfiles-setup.service ] || rm -f $i; done); \
rm -f /lib/systemd/system/multi-user.target.wants/*;\
rm -f /etc/systemd/system/*.wants/*;\
rm -f /lib/systemd/system/local-fs.target.wants/*; \
rm -f /lib/systemd/system/sockets.target.wants/*udev*; \
rm -f /lib/systemd/system/sockets.target.wants/*initctl*; \
rm -f /lib/systemd/system/basic.target.wants/*;\
rm -f /lib/systemd/system/anaconda.target.wants/*;
# nginx-php72源
RUN yum -y upgrade;\
#RUN rpm -Uvh https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm;\
#rpm -Uvh https://mirror.webtatic.com/yum/el7/webtatic-release.rpm;\
yum clean all;
VOLUME [ "/sys/fs/cgroup" ]
CMD ["/usr/sbin/init"]
#docker run -it --privileged --hostname="centos7-systemd" --name c7-systemd -v /sys/fs/cgroup:/sys/fs/cgroup:ro local/c7-systemd /bin/bash
