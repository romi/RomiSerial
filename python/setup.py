from setuptools import setup

setup(
    name='romiserial',
    version='0.1.0',    
    description='A library for serial communication (UART) with improved error detection and recovery.',
    url='https://github.com/romi/RomiSerial',
    author='Peter Hanappe, Doug Boari',
    author_email='peter.hanappe@sony.com',
    license='LGPL v2.1',
    packages=['romiserial'],
    install_requires=['pyserial', 'crc8'],

    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Science/Research',
        'License :: OSI Approved :: GNU Lesser General Public License v2 or later (LGPLv2+)',  
        'Operating System :: POSIX :: Linux',        
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.10',
    ],
)
