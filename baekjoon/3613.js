const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

rl.on('line', line => {
	switch(true) {
		case /[a-z]([A-Z][a-z]*)+/.test(line):
			console.log(line.replace(/[A-Z]/g, s => '_' + s.toLowerCase()));
			break;

		case /[a-z]+(_[a-z]+)+/.test(line):
			console.log(line.replace(/_[a-z]/g, s => s.substring(1, 2).toUpperCase()));
			break;

		default:
			console.log('Error!');
	}
	
	rl.close();
}).on('close', () => {
	process.exit();
});