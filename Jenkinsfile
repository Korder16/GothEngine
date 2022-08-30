pipeline {
    agent any

    options {
        skipDefaultCheckout(true)
    }

    stages {
        stage('Checkout') {
            steps {
                cleanWs()
                checkout scm
            }
        }

        stage('CMake') {
            steps {
                cmakeBuild buildType: 'Release', 
                    cleanBuild: true, 
                    buildDir: 'build',
                    installation: 'InSearchPath'
            }
        }

        stage('Build') {
            steps {
                sh 'pwd'
                sh 'ls build'
                sh 'cd build/'
                sh 'pwd'
                sh 'make'
            }
        }

        stage('Tests') {
            steps {
                sh 'tree'
                sh './build/bin/math_tests'
            }
        }
    }

    post {
        always {
            cleanWs(cleanWhenNotBuilt: false,
                    deleteDirs: true,
                    disableDeferredWipeout: true,
                    notFailBuild: true,
                    patterns: [[pattern: '.gitignore', type: 'INCLUDE'],
                               [pattern: '.propsfile', type: 'EXCLUDE']])
        }
    }
}