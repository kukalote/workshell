# sudo mkdir /usr/local/share/servers
# export PATH=$PATH:/usr/local/share/servers
#
# sudo mkdir /usr/local/share/servers/canal/
# sudo ln -s /usr/local/share/canal/bin/restart.sh  /usr/local/share/servers/canal/restart.sh
# sudo ln -s /usr/local/share/canal/bin/stop.sh  /usr/local/share/servers/canal/stop.sh
# sudo ln -s /usr/local/share/canal/bin/startup.sh  /usr/local/share/servers/canal/startup.sh 
#
# sudo mkdir /usr/local/share/servers/zookeeper
# sudo ln -s /usr/local/share/zookeeper3.4/bin/zkCli.sh /usr/local/share/servers/zookeeper/zkCli.sh
# sudo ln -s /usr/local/share/zookeeper3.4/bin/zkServer.sh /usr/local/share/servers/zookeeper/zkServer.sh
#
# sudo mkdir /usr/local/share/servers/rocketmq
# sudo ln -s /usr/local/share/rocketmq4.3/distribution/target/apache-rocketmq/bin/mqnamesrv /usr/local/share/servers/rocketmq
# sudo ln -s /usr/local/share/rocketmq4.3/distribution/target/apache-rocketmq/bin/mqbroker /usr/local/share/servers/rocketmq
#

# maven 
export MVN_HOME=/usr/local/share/maven3.6
export M2_HOME=/home/uxin/.m2/repository
export CLASSPATH=$CLASSPATH:$MVN_HOME:$M2_HOME
export PATH=$PATH:$M2_HOME/bin/


# canal-server
export CANAL_SERVER_HOME=/usr/local/share/canal
#export PATH=$PATH:$CANAL_SERVER_HOME/bin/

# canal-adapter
export CANAL_ADAPTER_HOME=/usr/local/share/canal-adapter

# zookeeper
export ZUKEEPER_HOME=/usr/local/share/zookeeper3.4
#export PATH=$PATH:$ZUKEEPER_HOME/bin/

# rocketmq
export RKTMQ_HOME=/usr/local/share/rocketmq4.3/distribution/target/apache-rocketmq
#export PATH=$PATH:$RKTMQ_HOME/bin/

# kafka
export KFK_HOME=/usr/local/share/kafka2.11
#export PATH=$PATH:$KFK_HOME/bin/


# elasticsearch
export ES_HOME=/usr/local/share/elasticsearch-6.2.3
#export PATH=$PATH:$ES_HOME/bin/


# kibana
export KIBANA_HOME=/usr/local/share/kibana-6.2.3


# Canal-Server Manage
#CANAL_SERVER=$SELFSERVERS/canal
canal()
{
    echo "canal-start        : start  [ sudo sh $CANAL_SERVER_HOME/bin/startup.sh ]"
    echo "canal-stop         : stop  [ sudo sh $CANAL_SERVER_HOME/bin/stop.sh ]"
    echo "canal-conf         : canal conf [ sudo vim $CANAL_SERVER_HOME/conf/canal.properties ]"
    echo "canal-example-conf : example conf [ sudo vim $CANAL_SERVER_HOME/conf/example/instance.properties ]"
    echo "canal-log          : canal log [ tail -f $CANAL_SERVER_HOME/logs/canal/canal.log ]"
    echo "canal-example-log  : example log  [ tail -f $CANAL_SERVER_HOME/logs/example/example.log ]"
}
canal-start()
{
    sudo sh $CANAL_SERVER_HOME/bin/startup.sh
}
canal-stop()
{
    sudo sh $CANAL_SERVER_HOME/bin/stop.sh
}
canal-conf()
{
    sudo vim $CANAL_SERVER_HOME/conf/canal.properties
}
canal-example-conf()
{
    sudo vim $CANAL_SERVER_HOME/conf/example/instance.properties
}
canal-log()
{
    tail -f $CANAL_SERVER_HOME/logs/canal/canal.log
}
canal-example-log()
{
    tail -f $CANAL_SERVER_HOME/logs/example/example.log
}


# Canal-adapter Manage
canal-adapter()
{
    echo "canal-adapter-start  : start  [ sudo $CANAL_ADAPTER_HOME/bin/startup.sh ]"
    echo "canal-adapter-stop   : stop  [ sudo $CANAL_ADAPTER_HOME/bin/stop.sh ]"
    echo "canal-adapter-log    : log  [ tail -f $CANAL_ADAPTER_HOME/logs/adapter.log ]"
}
canal-adapter-start()
{
    sudo $CANAL_ADAPTER_HOME/bin/startup.sh
}
canal-adapter-stop()
{
    sudo $CANAL_ADAPTER_HOME/bin/stop.sh
}
canal-adapter-log()
{
    tail -f $CANAL_SERVER_HOME/logs/adapter.log
}

# Zookeeper Manage
zookeeper()
{
    echo "zookeeper-start  : start  [ sudo $ZUKEEPER_HOME/bin/zkServer.sh start ]"
    echo "zookeeper-stop   : stop   [ sudo $ZUKEEPER_HOME/bin/zkServer.sh stop ]"
    echo "zookeeper-status : status [ sudo $ZUKEEPER_HOME/bin/zkServer.sh status ]"
    echo "zookeeper-cli    : zookeeper client [ sudo $ZUKEEPER_HOME/bin/zkCli.sh ]"

}
zookeeper-start()
{
    sudo $ZUKEEPER_HOME/bin/zkServer.sh start
}
zookeeper-stop()
{
    sudo $ZUKEEPER_HOME/bin/zkServer.sh stop
}
zookeeper-status()
{
    sudo $ZUKEEPER_HOME/bin/zkServer.sh status
}
zookeeper-cli()
{
    sudo $ZUKEEPER_HOME/bin/zkCli.sh
}

# RocketMQ Manage
rocketmq()
{
    echo "rocketmq-start         : name service start [ sudo nohup sh $RKTMQ_HOME/bin/mqnamesrv >/var/log/rocketmqlogs/namesrv.log& ]"
    echo "rocketmq-broker-start  : broker start [ sudo nohup sh $RKTMQ_HOME/bin/mqbroker -n localhost:9876 >/var/log/rocketmqlogs/broker.log& ]"

    echo "rocketmq-log           : name logs [ tail -f /var/log/rocketmqlogs/namesrv.log ]"
    echo "rocketmq-broker-log    : name logs [ tail -f /var/log/rocketmqlogs/broker.log ]"

    echo "rocketmq-stop          : name service stop [ sudo sh $RKTMQ_HOME/bin/mqshutdown broker ]"
    echo "rocketmq-broker-stop   : broker stop [ sudo sh $RKTMQ_HOME/bin/mqshutdown namesrv ]"
}
rocketmq-start()
{
    sudo nohup sh $RKTMQ_HOME/bin/mqnamesrv >/var/log/rocketmqlogs/namesrv.log&
}
rocketmq-broker-start()
{
    sudo nohup sh $RKTMQ_HOME/bin/mqbroker -n localhost:9876 >/var/log/rocketmqlogs/broker.log&
}
rocketmq-log()
{ 
    tail -f /var/log/rocketmqlogs/namesrv.log
}
rocketmq-broker-log()
{
    tail -f /var/log/rocketmqlogs/broker.log
}
rocketmq-stop()
{
    sudo sh $RKTMQ_HOME/bin/mqshutdown broker
}
rocketmq-broker-stop()
{
    sudo sh $RKTMQ_HOME/bin/mqshutdown namesrv
}


# kafka Manage
kafka()
{
    echo "kafka-start          : start  [ sudo $KFK_HOME/bin/kafka-server-start.sh $KFK_HOME/config/server.properties ]"
    echo "kafka-stop           : stop  [ sudo sh $KFK_HOME/bin/kafka-server-stop.sh $KFK_HOME/config/server.properties ]"
    echo "kafka-topic-create   : topic create  [ sudo $KFK_HOME/bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 1 --partitions 1 --topic test ]"
    echo "kafka-topic-list     : top list  [ sudo $KFK_HOME/bin/kafka-topics.sh --list --zookeeper localhost:2181 ]"
    echo "kafka-producer-start : customer start  [ sudo $KFK_HOME/bin/kafka-console-producer.sh --broker-list localhost:9092 --topic test ]"
    echo "kafka-consumer-start : customer start  [ sudo $KFK_HOME/bin/kafka-console-consumer.sh --bootstrap-server localhost:9092 --topic test --from-beginning ]"
}
kafka-start()
{
    sudo $KFK_HOME/bin/kafka-server-start.sh $KFK_HOME/config/server.properties 
}
kafka-stop()
{
    sudo sh $KFK_HOME/bin/kafka-server-stop.sh $KFK_HOME/config/server.properties
}
kafka-topic-create()
{
    sudo $KFK_HOME/bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 1 --partitions 1 --topic test
}
kafka-topic-list()
{
    sudo $KFK_HOME/bin/kafka-topics.sh --list --zookeeper localhost:2181
}
kafka-producer-start()
{
    sudo $KFK_HOME/bin/kafka-console-producer.sh --broker-list localhost:9092 --topic test
}
kafka-consumer-start()
{
    sudo $KFK_HOME/bin/kafka-console-consumer.sh --bootstrap-server localhost:9092 --topic test --from-beginning
}

# elasticsearch manage
elasticsearch()
{
    echo "elastic-start  : start  [ su elastic; $ES_HOME/bin/elasticsearch ]"
    echo "elastic-status : status [ curl 'http://localhost:9200/?pretty' ] "
}

# kibana manage
kibana()
{

    echo "kibana-start  : start  [ $KIBANA_HOME/bin/kibana ]"
}
kibana-start()
{
    sudo $KIBANA_HOME/bin/kibana
}
