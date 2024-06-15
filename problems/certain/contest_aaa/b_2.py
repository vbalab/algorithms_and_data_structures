import sys
import calendar
from datetime import datetime


if __name__ == "__main__":
    string = sys.stdin.read()

    format_ = string.split('.')[-1]

    if (string[0] == 'I'):
        dt_ = string.split("_")[1]
        dt = datetime.strptime(dt_, '%Y%m%d').date()
    elif (string[0] == 'D'):        
        dt_ = string[5:15]
        dt = datetime.strptime(dt_, '%Y-%m-%d').date()
    else:
        dt_ = string[:8]
        dt = datetime.strptime(dt_, '%Y%m%d').date()

    day = dt_[-2:]

    print(f"{dt.year}_{calendar.month_abbr[dt.month]}_{day}_PYTHON_CONFERENCE.{format_}")