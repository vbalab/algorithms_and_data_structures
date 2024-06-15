import sys
import calendar
from datetime import datetime


if __name__ == "__main__":
    input_ = sys.stdin.read().strip().split('\n')
    n = len(input_)


    events_order = []
    events = {}
    counter = {}


    n_events = 0
    while (input_[n_events][-1].isdigit()):
        event = input_[n_events].split(" ")

        date = f"{event[1]}-{event[2]}-{event[3]}"
        events[date] = event[0]
        events_order.append(event[0])

        counter[date] = 1

        n_events += 1


    ans = []
    for j in range(n_events, n):
        string = input_[j]

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

        dt_ = str(dt)
        day = dt_[-2:]

        ans.append(f"{dt.year}_{calendar.month_abbr[dt.month]}_{day}_{events[dt_]}_{counter[dt_]}.{format_}")
        counter[dt_] += 1


    events_order = events_order[::-1]
    ans.sort()
    for event_name in events_order:
        for i in ans:
            if event_name in i:
                print(i)
