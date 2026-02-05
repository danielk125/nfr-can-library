import pandas as pd
import argparse
from can_parser import CANDatabase

def generate_can_code(db_file, naming_convention, output_file):
    df = pd.read_csv(db_file)
    # Ensure data has necessary columns
    df = df.dropna(subset=['Message Name', 'Start Bit', 'Size (bits)', 'Factor', 'Offset'])
    # Combine dataframes named columns with the rest of the values
    lists = [list(df.columns), *df.values.tolist()]
    db = CANDatabase(lists)

    buses = db.get_buses()
    messages = db.get_messages().values()

    with open(output_file, "w") as f:
        # Necessary includes
        f.write("#include \"CAN_interface.cpp\"\n")

        
        f.write("namespace CANDBC {\n")

        for message in messages:
            signals = message.get_signals()
            for signal in signals:
                signal_str = signal.as_cpp_code(naming_convention)
                f.write(signal_str + "\n")

            can_msg_str = message.as_cpp_receive_code(buses[0].get_cpp_bus_name(naming_convention), naming_convention)
            f.write(can_msg_str + "\n\n")
        f.write("}")
        

parser = argparse.ArgumentParser()
parser.add_argument("dbc_file", help="DBC file that is read and utilized to generate the cpp code.")
parser.add_argument("-o", "--output_file", help = "Provide a designated output file. Default is can_dbc.hpp", default="can_dbc.hpp")
parser.add_argument("-c", "--convention", help="Provide a naming convention. Default is PascalCase", default="PascalCase")
args = parser.parse_args()
dbc_file = args.dbc_file
output_file = args.output_file
naming_convention = args.convention
generate_can_code(dbc_file, naming_convention, output_file)