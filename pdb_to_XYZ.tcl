
mol delete all
mol new $initial_pdb

set initial_pdb protein.pdb
set textfile protein.XYZ

set OUTPUT [open $textfile w]

set p [atomselect top protein]
set n [$p num]
set atoms [$p get index]
puts $OUTPUT "$n"; flush stdout
puts $OUTPUT "one frame"; flush stdout
for {set i 0} {$i < $n} {incr i} {
	set index [lindex $atoms $i]
	puts $i
	set sel [atomselect top "index $index"]	
	set x [$sel get x]
	set y [$sel get y]
	set z [$sel get z] 
	set name [$sel get name]
	puts $OUTPUT "$name $x $y $z"; flush stdout
}
close $OUTPUT

