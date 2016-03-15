'use strict';

modules.exports = function(grunt) {

	grunt.initConfig({

		config: {
			c: {
				all_files: '**/*.c',
			},
		},

		shell: {

			compiler: {
				command: 'gcc <%= inputFile %> -o <%= outputFile %> -lncurses',
				options: {
					stdout: true,
					stderr: true,
				},
			},

		},

		watch: {
			compiler: {
				files: 'config.c.all_files',
				tasks: 'shell',
			},
		},

	});

	grunt.event.on('watch', function(filename) {
		grunt.log.writeln(target + ': ' + filepath + ' has ' + action);
	});

	grunt.loadNpmTasks('grunt-contrib-clean');
	grunt.loadNpmTasks('grunt-contrib-watch');
	grunt.loadNpmTasks('grunt-shell');

	grunt.registerTask('setup', []);

};
