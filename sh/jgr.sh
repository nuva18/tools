if [ $# -ne 1 ]; then
    echo "usage: jgr <input>"
    exit 1 
fi 

input=$1 
base=`basename $1`
output=`echo $base | sed 's/\.jgr/\.jpg/'`

jgraph -P $input | ps2pdf - | convert -density 300 - -quality 100 $output
