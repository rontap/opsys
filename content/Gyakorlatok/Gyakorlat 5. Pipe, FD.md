
## Emlékeztető

manpages használta: pl pipe-ra:
man 3 pipe --> C-s használat
man 7 pipe --> általános leírás

Beépített pipe-ok:
`ls | wc -l`
![[Pasted image 20240309195120.png]]


```shell
mkfifo my_pipe
echo "5 hello" > my_pipe
cat my_pipe
	```


```
> - redirect standard output
< - redirect standard input
>> - send in addition
2>&1 - standard error redirect to std in
```
![[Pasted image 20240309191357.png]]![[Pasted image 20240309191410.png]]

`( echo "5 hello" 1>&9 ) 9>&1 > cat`


sprintf / write to standard output

# /PROC

/proc/cmdline
/proc/meminfo
/proc/PID/??
- status
- cmdlint
- cwd
- fd !


`mkfifo myfifo 
wc -l < myfifo & 
ls -l | tee myfifo | sort -k5n
`