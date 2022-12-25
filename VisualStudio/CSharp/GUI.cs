using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharp
{
    public partial class GUI : Form
    {
        public GUI()
        {
            InitializeComponent();
            this.restartToolStripMenuItem.Click += RestartToolStripMenu;
            this.exitToolStripMenuItem.Click += (object sender, EventArgs _) => Application.Exit();
        }

        private void RestartToolStripMenu(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        }
    }
}
