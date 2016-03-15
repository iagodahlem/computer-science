'use strict';

var path = require('path');

module.exports = (grunt) => {

	grunt.initConfig({

		config: {

			c: {
				all_files: 'algoritmos-e-programacao-2/**/*.c',
			},

		},

		shell: {

			compiler: {
				command: 'gcc <%= inputFile %> -o <%= outputFile %> -lncurses && echo <%= inputFile %>',
				options: {
					stdout: true,
					stderr: true,
				},
			},

		},

		watch: {

			compiler: {
				files: '<%= config.c.all_files %>',
				tasks: 'shell',
				option: {
					event: 'changed',
				},
			},

		},

	});

	grunt.event.on('watch', (action, filepath, target) => {
		var fileToCompile = path.parse(filepath);
		grunt.config.set(inputFile, fileToCompile.base);
		grunt.config.set(outputFile, fileToCompile.name);
	});

	require('load-grunt-tasks')(grunt);

	grunt.registerTask('compiler', ['watch']);

};
