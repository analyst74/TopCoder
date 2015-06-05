using Microsoft.VisualStudio.TestTools.UnitTesting;
using _555.div2._255;

namespace _555.div2
{
    [TestClass]
    public class Tests255
    {
        private XorBoardDivTwo _xorBoard;

        [TestInitialize]
        public void TestInitialize()
        {
            _xorBoard = new XorBoardDivTwo();
        }

        [TestMethod]
        public void Test0()
        {
            var board = new string[]
                            {
                                "101",
                                "010",
                                "101"
                            };
            Assert.AreEqual(9, _xorBoard.theMax(board));
        }
    }
}
