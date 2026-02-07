import pandas as pd
import argparse
from can_parser import CANDatabase

def generate_can_code(db_file, naming_convention, output_file):
    df = pd.read_csv(db_file)
    # Ensure data has necessary columns and clean the data
    df = df.dropna(subset=['Message Name', 'Start Bit', 'Size (bits)', 'Factor', 'Offset'])
    df = df.drop(df.columns[df.columns.str.contains('unnamed', case = False)], axis = 1)
    # Combine dataframes named columns with the rest of the values
    lists = [list(df.columns), *df.values.tolist()]
    db = CANDatabase(lists)

    buses = db.get_buses()
    messages = db.get_messages().values()
    
    with open(output_file, "w") as f:
        file_w_str = ""
        # Necessary includes
        file_w_str += "#include \"CAN_interface.cpp\"\n"
        
        # Provide namespace wrapper
        file_w_str += "namespace CANDBC {\n"
        for message in messages:
            signals = message.get_signals()
            for signal in signals:
                signal_str = signal.as_cpp_code(naming_convention)
                if signal_str not in file_w_str:
                    file_w_str += f"{signal_str}\n"
                # f.write(signal_str + "\n")

            bus = buses[0].get_cpp_bus_name(naming_convention)
            can_msg_str = message.as_cpp_receive_code(bus, naming_convention)
            file_w_str += f"{can_msg_str}\n\n"
        file_w_str += "}"
        f.write(file_w_str)
        
        

parser = argparse.ArgumentParser()
parser.add_argument("dbc_file", help="DBC file that is read and utilized to generate the cpp code.")
parser.add_argument("-o", "--output_file", help = "Provide a designated output file. Default is can_dbc.hpp", default="can_dbc.hpp")
parser.add_argument("-c", "--convention", help="Provide a naming convention. Default is PascalCase", default="PascalCase")
args = parser.parse_args()
dbc_file = args.dbc_file
output_file = args.output_file
naming_convention = args.convention
generate_can_code(dbc_file, naming_convention, output_file)