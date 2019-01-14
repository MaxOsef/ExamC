# ExamC
## --------------  C development command -------------------------------------
### Build and run C project
alias bnr='bnr(){ gcc "$1" -o "$2" && ./"$2"; unset -f bnr; }; bnr'

### Build C project
alias b='b(){ gcc "$1" -o "$2"; unset -f b; }; b'

### Run C project
alias run='run(){ ./"$1"; unset -f run; }; run'


## --------------  Tmux section ----------------------------------------------
### Open C session with Tmux
alias devCTmux='~/.tmux/dev_C_tmux.sh'
