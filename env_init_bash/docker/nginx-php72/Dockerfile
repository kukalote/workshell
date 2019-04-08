FROM local/c7-systemd

RUN yum -y install php72w-fpm php72w php72w-cli php72w-common php72w-devel php72w-bcmath \
php72w-dba php72w-imap php72w-mbstring php72w-mysql php72w-opcache php72w-pdo php72w-xml \
php72w-pecl-memcached php72w-pecl-redis php72w-pecl-xdebug;
RUN yum -y install nginx; 
RUN yum clean all;
RUN systemctl enable php-fpm.service; systemctl enable nginx.service

EXPOSE 80
CMD ["/usr/sbin/init"]
