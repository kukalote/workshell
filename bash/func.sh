alias rm="rmbak $*";
alias ld="lsdir $*"
alias open="opengpk $*"
alias svndiffile="svnLog $*";
export crash_dir="/var/crash/"
export cshell_dir=$selfwork'/cshell'
export current_work_pid='/tmp/current_work_pid'

# 删除文件时将文件转移至删除备份目录
rmbak () 
{
    backdir=`currentBackupDir`
    if [ ! -d '$backdir' ]
    then
        mkdir -p $backdir
    fi

    $(mv $* $backdir)
}

# 返回删除备份目录地址
currentBackupDir () 
{
    date_dir=$(date +%Y%m%d)
    current_dir=$crash_dir'rm_'$date_dir
    echo  $current_dir
}

# 清理七天前删除文件
sycleClearBackupDir () 
{
    result=$(find $crash_dir -type d -name 'rm_*' -ctime +7 -print0 | xargs -0 rm -r 2> /dev/null)
    if [ $? =  0 ]
    then
        echo '七天前垃圾文件已清理'
    fi
    return 0
} 
# 重置/切换当前工作目录
worknow () 
{
    if [ $# -gt 0 ]
    then
        # 将 $1 写入文件，并保存为当前工作目录
        resetWorkDir $1
        workcurrent=$1
    else
        workcurrent=`getCurrentWorkDir`
    fi
    # 当前bash操作,如果用 $()，则为子bash执行
    cd $workcurrent
}

# 设置当前工作目录
resetWorkDir () 
{
    workdir=`realpath $1`
    echo $workdir > $current_work_pid
    return 0
}

# 获取工作目录
getCurrentWorkDir () 
{
    # 如果无文件
    if [ ! -f $current_work_pid ]
    then
#        echo 'please insert current work dir' >&1
        read workcurrent
        # 写入指定文件
        echo $workcurrent > $(echo $current_work_pid)
    fi
    workcurrent=`awk 'NR==1' $current_work_pid`
    echo $workcurrent
}

# 将当前目录设定为工作目录
setworknow () 
{
    worknow `pwd`
}

# svn 查看当前用户的参数
svnLog () 
{
    user=''
    output=''
    while getopts "n:u:r:" opt;
    do
        case $opt in
            n)
                num=$OPTARG
                output=$(svn log -v -l $num)
                ;;
            r)
                reversion=$OPTARG
                output=$(svn log -v -r $reversion)
                ;;
            u)
                user=$OPTARG
                ;;
            \?)
                echo "Invalid option: -$OPTARG"
                exit;
                ;;
        esac
    done
    if [ $user ]
    then
        output=$(echo $output | sed -n "/$user/,/------$/p")
    fi
    echo $output | sed -n '/Changed paths:/,/^$/p' | sort | uniq | grep .
}

# todo work
todo () 
{
    todo_script=$cshell_dir'/todo.out'
    $todo_script
}


lsdir() 
{
    ls -lF $* | grep "/$"
}

dircd()
{
    cd -$1
}

opengpk()
{
    xdg-open $* 2>/dev/null
}

isCentOS()
{
    result=$( head -1 /etc/os-release | grep 'CentOS' )
    if [[ result != '' ]]
    then
        return 0;
    else
        return 1;
    fi
}
#todo
sycleClearBackupDir
#rmbak
#currentBackupDir
#worknow



