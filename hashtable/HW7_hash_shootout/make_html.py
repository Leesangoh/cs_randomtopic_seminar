import sys
f = open('charts-template.html', 'r')
html_template = f.read()
f_2 = open('charts.html', 'w')
f_2.write(html_template.replace('__CHART_DATA_GOES_HERE__', sys.stdin.read()))
