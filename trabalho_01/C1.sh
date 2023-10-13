#!/bin/bash
total_time=0
while read -r SCRIPT_SOURCE_LINE; do
	{ time -p command ${SCRIPT_SOURCE_LINE}; } 2> timing_output
	return_value=$?
	real_time=$(grep -Eo 'real [0-9]+\.[0-9]+' timing_output | cut -d ' ' -f 2)
	if [ $return_value -ne 0 ]; then
		error="FAZER TRATAMENTO DE ERRO!"
		printf "> Erro: %s\n" "$error"
	fi
	printf "> Demorou %.1f segundos, retornou %d\n" $real_time $return_value
	total_time=$(echo "scale=2; $total_time + $real_time" | bc)
done
printf ">> O tempo total foi de %.1f segundos\n" $total_time
