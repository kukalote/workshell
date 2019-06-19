# GO语言安装方法
#######################################################################
# 1. 下载地址 : https://golang.org/dl/
# 2. tar -C /usr/local -xzf go1.12.6.linux-amd64.tar.gz
# 3. export PATH=$PATH:/usr/local/go/bin
# 4. export GEPATH=/var/www/go
# 5. 代码测试 $ go run test.go
#######################################################################


export GOROOT=/usr/local/go                                                                                                                      
export GOBIN=$GOROOT/bin
export PATH=$PATH:$GOBIN
export GOPATH=/var/www/go
