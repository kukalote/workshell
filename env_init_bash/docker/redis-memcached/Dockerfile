FROM local/c7-systemd

RUN yum -y update;
RUN yum -y install redis; yum -y install memcached;
RUN yum clean all;
RUN chmod -R 777 /var/log/redis/;
COPY ./redis.conf /etc/redis.conf
RUN systemctl enable redis.service; systemctl enable memcached.service

EXPOSE 11211
EXPOSE 6379
CMD ["/usr/sbin/init"]
