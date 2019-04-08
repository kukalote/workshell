FROM local/c7-systemd

# mysql源
RUN rpm -Uvh https://dev.mysql.com/get/mysql80-community-release-el7-2.noarch.rpm;

RUN yum -y install mysql-community-server; yum clean all; systemctl enable mysqld.service;

EXPOSE 3306
CMD ["/usr/sbin/init"]
