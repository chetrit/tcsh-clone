# tcsh-clone

> tcsh-clonde is as project that aims to reproduce a complete unix shell, in this case tcsh shell. This project is the successor of [minimalist-shell](https://github.com/chetrit/minimalist-shell), but with way more features: more built-ins, an history, aliases handling, better error handling ...

You can find the documentation of tcsh [here](https://linux.die.net/man/1/tcsh), which hence is the documentation of this project (partially). 

# Installation, compilation and utilization
#### Installation
After cloning the repository, you have nothing else to install since it is in C and without external libraries !

#### Compilation
Compilation of binary using Makefile:
```
make
```

#### Utilization
Launch the shell
```
./42sh
```

# Full Example

```
./42sh
[chetrit@chetrit tcsh-clone]$ ls
42sh  include  Makefile  src  tests
[chetrit@chetrit tcsh-clone]$ echo toto > tata
[chetrit@chetrit tcsh-clone]$ where cd
cd is a shell built-in
/usr/bin/cd
/bin/cd
[chetrit@chetrit tcsh-clone]$ repeat 3 echo a
a
a
a
[chetrit@chetrit tcsh-clone]$ ls | grep /bin/ls
[chetrit@chetrit tcsh-clone]$ rm tata
[chetrit@chetrit tcsh-clone]$ echo toto >> tata
[chetrit@chetrit tcsh-clone]$ cat tata
toto
[chetrit@chetrit tcsh-clone]$ echo toto >> tata
[chetrit@chetrit tcsh-clone]$ cat tata
toto
toto
[chetrit@chetrit tcsh-clone]$ echo `echo toto`
toto
[chetrit@chetrit tcsh-clone]$ which cd
cd: shell built-in command.
[chetrit@chetrit tcsh-clonde]$ cd Makefile
Makefile: Not a directory.
```

>Don't worry, the shell makes a complete copy of your actual environment when launching it, which means you can mess up with your environnement without taking any risks !
