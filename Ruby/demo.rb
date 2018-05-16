#!/usr/bin/env ruby
#
#encoding: utf-8
#
#Author: wpc
#Created: 2018-05-16 22:34:09


#使用Ruby pack相关操作进行
#https://blog.bigbinary.com/2011/07/20/ruby-pack-unpack.html
#

if ARGV.length != 1
    puts <<-END
    Usage:
        #{__FILE__} <data>
    END
    exit 1
end


data = File.read(ARGV[0])

magic=data[0..3]
length=data[4..7].unpack('L')

puts magic,length
