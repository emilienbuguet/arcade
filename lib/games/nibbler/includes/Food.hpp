namespace arc::games {
    class Food {
        public:
            Food();
            ~Food();

            /**
             * @brief Get the Pos X object
             *
             * @return int
             */
            int getXpos() const;

            /**
             * @brief Get the Pos Y object
             *
             * @return int
             */
            int getYpos() const;

            /**
             * @brief Set the Pos X and Y object
             *
             * @param x
             */
            void setPos(int x, int y);

        private:
            int pos_x;
            int pos_y;
    };
}