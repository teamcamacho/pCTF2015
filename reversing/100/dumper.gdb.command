(gdb) show user dumper
User command "dumper":
  while ($rip != 0x400cba) 
    ni
    print $rax
    print $rbx
    print $rcx
    print $rdx
    print $rdi
    print $rsi
    print $rbp
    print $rsp
    x/1i $rip
  end

(gdb) 
