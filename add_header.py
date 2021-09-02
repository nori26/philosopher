import sys
import os
from datetime import datetime

def main():
    name = "nosuzuki"
    mail = f"{name}@student.42tokyo.jp"
    files = sys.argv[1:]
    start = '/* ************************************************************************** */'
    for file in files:
        s = None
        now = time(datetime.now())
        filename = os.path.basename(file)
        with open(file, 'r') as f:
            s = f.read()
            if s[:len(start)] == start:
                continue
        with open(file, 'w') as f:
            f.write(f'''\
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   {filename.ljust(51)                               }:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {adjust(f"{name} <{mail}>", 43)           }+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: {now} by {adjust(name, 17)             } #+#    #+#             */
/*   Updated: {now} by {adjust(name, 17)             }###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

''' + s)

def time(time):
    return time.strftime("%Y/%m/%d %H:%M:%S")

def adjust(str, size):
    return str.ljust(size)[:size]

if __name__ == "__main__":
    main()