# 如何拉取指定文件夹
先进入到你要存放的路径
创建一个空的本地仓库

$ git init

连接远程仓库GitHub

$ git remote add -f origin <url>

我的操作：$ git remote add -f origin https://github.com/aliyun/alicloud-android-demo.git

然后控制台会显示一些updating...信息。注意，这里的url必须是.git结尾的。

开启sparse checkout 模式  ----如果我只是上传，是不是后续的步骤就可以不要了？？也需要，需要pull更新到库上最新

$ git config core.sparsecheckout true

简单解释一下：

Git1.7.0以后加入了Sparse Checkout模式，这使得Check Out指定文件或者文件夹成为可能。

告诉Git哪些文件或者文件夹是你真正想Check Out的
(它们作为一个列表保存在 .git/info/sparse-checkout 文件中。)

例如：
$ echo README.md >> .git/info/sparse-checkout
  
$ echo apps/register.go >> .git/info/sparse-checkout
  
$ echo resource >> .git/info/sparse-checkout

最后一步，拉取想要的分支

$ git pull origin master

参考文章：
  https://www.jianshu.com/p/74a0441ed9b7
  https://blog.csdn.net/qq_39083004/article/details/80339307?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163385112516780261932877%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=163385112516780261932877&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_v2~rank_v29-1-80339307.pc_v2_rank_blog_default&utm_term=%E4%BB%8Egithub%E4%B8%8Aclone%E4%B8%80%E4%B8%AA%E6%96%87%E4%BB%B6%E5%A4%B9&spm=1018.2226.3001.4450
