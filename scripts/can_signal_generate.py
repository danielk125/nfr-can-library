import pandas as pd
from can_parser import CANDatabase


def generate_can_code(db_file, naming_convention, output_file):
    df = pd.read_csv(db_file)
    df = df.dropna(subset=['Message Name', 'Start Bit', 'Size (bits)', 'Factor', 'Offset'])
    lists = [list(df.columns), *df.values.tolist()]
    db = CANDatabase(lists)

    buses = db.get_buses()
    messages = db.get_messages().values()

    with open(output_file, "w") as f:

        # add interface
        # add includes


        for message in messages:
            signals = message.get_signals()
            for signal in signals:
                signal_str = signal.as_cpp_code(naming_convention)
                f.write(signal_str + "\n")

            can_msg_str = message.as_cpp_receive_code(buses[0].get_cpp_bus_name(naming_convention), naming_convention)
            f.write(can_msg_str + "\n\n")
        
# arg parser, naming conventions
# namespace, includes


generate_can_code("can_dbc.csv", "PascalCase", "can_signals.hpp")
