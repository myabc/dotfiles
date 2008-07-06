#PS1='\[\e[0;32m\]\u\[\e[m\] \[\e[1;34m\]\w\[\e[m\] \[\e[1;32m\]\$ \[\e[m\]\[\e[1;37m\] '

# source .bashrc if it's there
if [ -f ~/.bashrc ]; then
    . ~/.bashrc
fi

export JAVA_HOME=/System/Library/Frameworks/JavaVM.framework/Versions/1.5/Home
export JRUBY_HOME=/usr/local/jruby
export ANT_HOME=/usr/bin/ant
export M2_HOME=/usr/local/maven
export CATALINA_HOME=/usr/local/tomcat

PATH=$HOME/bin:/usr/local/bin:/opt/local/bin:/opt/local/sbin:$PATH:$JRUBY_HOME/bin:/usr/local/mysql/bin:/usr/local/php5/bin

export EDITOR='mate'
					# causes issues with crontab -e 
export SVN_EDITOR='mate -w'
export GIT_EDITOR='mate -w'

export PATH

if [ -f ~/.profile_private ]; then
  . ~/.profile_private
fi

# For DataObjects / DataMapper TESTING
export DO_MYSQL_SPEC_URI="mysql://root:$MYSQL_ROOT_PASS@localhost/do_mysql_test?socket=/var/mysql/mysql.sock"
export DO_MYSQL_SPEC_JDBC_URI="jdbc:mysql://localhost:3306/do_mysql_test?user=root&password=$MYSQL_ROOT_PASS"
export MYSQL_SPEC_URI="mysql://root:$MYSQL_ROOT_PASS@localhost/dm_core_test?socket=/var/mysql/mysql.sock"
