<?php
include "../library/public/autoload.class.php";

$handle = new Rss($_GET);
//echo $debug->getUrl();exit;    //输出请求链接
echo $handle->getResponse(); //输出请求结果

return 0;
