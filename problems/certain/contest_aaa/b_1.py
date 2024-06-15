import sys
import calendar
from datetime import datetime


if __name__ == "__main__":
    string = sys.stdin.read()


    format_ = string.split('.')[-1]

    dt_ = string.split("_")[1]
    dt = datetime.strptime(dt_, '%Y%m%d').date()

    day = dt_[-2:]

    print(f"{dt.year}_{calendar.month_abbr[dt.month]}_{day}_PYTHON_CONFERENCE.{format_}")
