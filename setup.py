from distutils.core import setup, Extension
path = '/usr/lib/'
incPath1 = '/home/susheel'
incPath = '/home/susheel/test'
libPath = '/home/susheel/.tmp/'

module1 = Extension('example',
                    extra_compile_args=['-I' + incPath, '-I' + incPath1],
                    library_dirs=[libPath, incPath],
                    libraries=['supc++'],
                    sources = ['firstPy.c'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
