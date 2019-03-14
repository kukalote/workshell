alias rm="rmbak $*";
alias lsdir="lsdir $*"
alias open="opengpk $*"
alias svndiffile="svnLog $*";
export crash_dir="/var/crash/"
export cshell_dir=$selfwork'/cshell'
export current_work_pid='/tmp/current_work_pid'

# 工作目录切换扩展
# wdls
# wd /tmp
# wd 1
# wd
# rmwd 1




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
    if [[ "$result" != "" ]]
    then
        return 0;
    else
        return 1;
    fi
}

############################
######## 工作目录切换工具
############################


# 添加/切换当前工作目录
wd () 
{
    if [ $# -gt 0 ]
    then
        # 输入序号与目录区分
        if [[ $1 == *[!0-9]* ]]
        then
            # 将 $1 写入文件，并保存为当前工作目录
            addWorkDir $1
            workcurrent=$1
        else 
            workcurrent=`getWorkDirByID $1`;
        fi
    else
        workcurrent=`getCurrentWorkDir`
    fi
    # 当前bash操作,如果用 $()，则为子bash执行
    cd $workcurrent
}

# 设置当前工作目录
addWorkDir () 
{
    wd=`realpath $1`
    echo $wd >> $current_work_pid
    return 0
}

# 展示工作目录列表
wdls()
{
    cat -n $current_work_pid
}

# 删除序号内的工作目录 
rmwd()
{
    rmline="$1d"
    cont=`sed $rmline $current_work_pid`
    echo $cont > $current_work_pid
    wdls
}

# 获取工作目录
getCurrentWorkDir () 
{
    # 如果无文件
    if [ ! -f $current_work_pid ]
    then
        read workcurrent
        # 写入指定文件
        echo $workcurrent > $(echo $current_work_pid)
    fi
    workcurrent=`awk 'NR==1' $current_work_pid`
    echo $workcurrent
}
# 获得序号下的地址
getWorkDirByID ()
{
    i=1;
    for l in $( cat $current_work_pid )
    do
        let "i += 1"
        if [ $i -gt $1 ]
        then
            echo $l
            break;
        fi
    done
    return 0
}


############################

#todo
sycleClearBackupDir
#rmbak
#currentBackupDir
#worknow



