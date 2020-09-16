#first check if file exist or not
if test ! -f nums
#if not, then create one
then
    echo 0 > nums
fi

#writing nums into the file, this is critical region
#this is why we should lock it

if ln nums nums.lock
then
    for i in {1..20};
    do
        n=`tail -1 nums`
        expr $n + 1 >>nums
    done
    
    #unlock as it left critical region
    rm nums.lock
fi
 
