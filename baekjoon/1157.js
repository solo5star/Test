const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

rl.on('line', line => {
	console.log(Object.entries(line.toUpperCase().split('')
		.reduce((acc, current) => {
				acc[current] = (acc[current] || 0) + 1;
				return acc;
			}, {}))
		.reduce((acc, current) => {
				return acc[1] === current[1] ? ['?', acc[1]]
					: acc[1] > current[1] ? acc
					: current;
			}, [ '?', 0 ])
			
			[0]);
	
	rl.close();
}).on('close', () => {
	process.exit();
});